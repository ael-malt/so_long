/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghosts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:02:35 by ael-malt          #+#    #+#             */
/*   Updated: 2023/07/16 18:40:23 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_list	*ft_chooseghcolor(t_game *game, int i, int dir)
{
	t_list	*anim;
	char	*s;
	int		j;

	j = 0;
	anim = NULL;
	s = NULL;
	s = ft_substr("sprites/Ghosts/R/", 0, 17);
	if (i > 0)
		ft_memset(&s[15], COLORS[i % 7], 1);
	if (dir == N)
		anim = ft_load_north(game, s, j);
	if (dir == S)
		anim = ft_load_south(game, s, j);
	if (dir == E)
		anim = ft_load_east(game, s, j);
	if (dir == W)
		anim = ft_load_west(game, s, j);
	free(s);
	return (anim);
}

void	ft_load_ghosts(t_game *game)
{
	t_player	*ghost;
	int			i;

	i = 0;
	ghost = game->gh;
	while (ghost)
	{
		ghost->sprites.up = ft_chooseghcolor(game, i, N);
		ghost->sprites.up_bak = ghost->sprites.up;
		ghost->sprites.down = ft_chooseghcolor(game, i, S);
		ghost->sprites.down_bak = ghost->sprites.down;
		ghost->sprites.right = ft_chooseghcolor(game, i, E);
		ghost->sprites.right_bak = ghost->sprites.right;
		ghost->sprites.left = ft_chooseghcolor(game, i, W);
		ghost->sprites.left_bak = ghost->sprites.left;
		ghost->sprites.panic = ft_load_panic(game, i);
		ghost->sprites.panic_bak = ghost->sprites.panic;
		ghost = ghost->next;
		i++;
	}
}

void	ft_put_ghosts(t_game *game)
{
	t_player	*ghost;

	ghost = game->gh;
	while (ghost)
	{
		mlx_put_image_to_window(game->id, game->w_id, game->sprites.black,
			ghost->win_pos.x, ghost->win_pos.y);
		if (ghost->dir == N && !game->panic_mode && ghost->moving)
			ft_anim_north(game, ghost);
		if (ghost->dir == S && !game->panic_mode && ghost->moving)
			ft_anim_south(game, ghost);
		if (((ghost->dir == E && ghost->moving)
				|| ghost->dir == ST) && !game->panic_mode)
			ft_anim_east(game, ghost);
		if (ghost->dir == W && !game->panic_mode && ghost->moving)
			ft_anim_west(game, ghost);
		if (game->panic_mode)
			ft_anim_panic(game, ghost);
		else if (!ghost->moving)
			ft_put_stopped(game, ghost);
		ghost = ghost->next;
	}
}

void	ft_update_ghosts(t_game *game)
{
	t_player	*ghost;
	t_player	*closest;
	int			dir;

	ghost = game->gh;
	while (ghost && !ghost->moving)
	{
		closest = ft_getnearestpac(game, ghost);
		dir = ft_choose_dir(game, ghost, closest);
		ghost->moving = 1;
		ft_move_ghost(dir, game, ghost);
		ghost = ghost->next;
	}
}

void	ft_move_ghost(int dir, t_game *game, t_player *gh)
{
	t_vector	old;

	old = ft_newvector(gh->pos.x, gh->pos.y);
	ft_memset(&game->map[gh->pos.y][gh->pos.x],
		'0', game->map[gh->pos.y][gh->pos.x] == 'G');
	if (dir == N)
		gh->pos.y--;
	if (dir == S)
		gh->pos.y++;
	if (dir == E)
		gh->pos.x++;
	if (dir == W)
		gh->pos.x--;
	gh->dir = dir;
	if (game->map[gh->pos.y][gh->pos.x] == 'P')
	{
		game->pac_dying = 1;
		gh->pos = old;
	}
}

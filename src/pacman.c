/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pacman.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-malt <ael-malt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:16:34 by ael-malt          #+#    #+#             */
/*   Updated: 2023/07/17 11:57:52 by ael-malt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_load_pacmans(t_game *game)
{
	t_player	*pacman;
	int			i;

	i = 0;
	pacman = game->pl;
	while (pacman)
	{
		pacman->sprites.up = ft_load_north(game, NULL, i);
		pacman->sprites.up_bak = pacman->sprites.up;
		pacman->sprites.down = ft_load_south(game, NULL, i);
		pacman->sprites.down_bak = pacman->sprites.down;
		pacman->sprites.left = ft_load_west(game, NULL, i);
		pacman->sprites.left_bak = pacman->sprites.left;
		pacman->sprites.right = ft_load_east(game, NULL, i);
		pacman->sprites.right_bak = pacman->sprites.right;
		pacman = pacman->next;
	}
}

void	ft_put_pacman(t_game *game)
{
	t_player	*pacman;

	pacman = game->pl;
	while (pacman)
	{
		mlx_put_image_to_window(game->id, game->w_id, game->sprites.black,
			pacman->win_pos.x, pacman->win_pos.y);
		if (pacman->dir == N && pacman->moving)
			ft_anim_north(game, pacman);
		if (pacman->dir == S && pacman->moving)
			ft_anim_south(game, pacman);
		if (pacman->dir == E && pacman->moving)
			ft_anim_east(game, pacman);
		if (pacman->dir == W && pacman->moving)
			ft_anim_west(game, pacman);
		if (pacman->dir == ST)
			mlx_put_image_to_window(game->id, game->w_id, game->sprites.pacman,
				pacman->win_pos.x, pacman->win_pos.y);
		else if (!pacman->moving)
			ft_put_stopped(game, pacman);
		pacman = pacman->next;
	}
}

void	ft_next_dir(t_game *game)
{
	t_player	*pac;
	int			n_pl;

	pac = game->pl;
	n_pl = game->lay->n_pl;
	while (pac)
	{
		if (!pac->moving)
		{
			ft_update_legal(game, pac);
			if (game->next_dir && ft_in_legal(pac, game->next_dir))
				pac->dir = game->next_dir;
			ft_move(pac->dir, game, pac);
			if (n_pl != game->lay->n_pl)
				break ;
		}
		pac = pac->next;
	}
}

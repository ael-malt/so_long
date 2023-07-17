/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:00:35 by ael-malt          #+#    #+#             */
/*   Updated: 2023/07/16 16:38:17 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_newdirection(t_game *game, int direction)
{
	t_player	*temp;

	temp = game->pl;
	if (game->n_moves < 9999)
	{
		game->n_moves++;
		ft_update_score(game);
	}
	while (temp)
	{
		game->next_dir = direction;
		temp = temp->next;
	}
}

int	ft_reset(t_game *game)
{
	t_lay	lay;
	char	**map;

	map = ft_dup_matrix(game->map_bak);
	if (!map)
		return (0);
	lay = game->lay_bak;
	if (game->map)
		ft_free_matrix(&game->map);
	free_sprites(game);
	ft_free_playerlist(game);
	mlx_clear_window(game->id, game->w_id);
	ft_printf("\n\033[0;93mGAME HAS BEEN RESET!\n\033[0;39m");
	ft_newgame(game, map, &lay);
	return (1);
}

int	ft_euclideandistance(t_vector src, t_vector dest)
{
	return (ft_sqrt(ft_recursive_power(dest.x - src.x, 2)
			+ ft_recursive_power(dest.y - src.y, 2)));
}

int	ft_swap_tile(t_vector old, t_vector new, t_game *game)
{
	t_player	*player;
	int			hide;

	player = game->pl;
	hide = 0;
	if (game->map[new.y][new.x] == 'E')
	{
		if (game->lay->n_collect)
			return (1);
		mlx_put_image_to_window(game->id, game->w_id, game->sprites.black,
			old.x * SIZE, old.y * SIZE);
		hide = ft_delete_player(game, old);
	}
	while (!hide && player)
	{
		if (player->pos.x == old.x && player->pos.y == old.y)
		{
			player->pos = ft_newvector(new.x, new.y);
			player->moving = 1;
		}
		player = player->next;
	}
	ft_memset(&game->map[new.y][new.x], game->map[old.y][old.x], !hide);
	ft_memset(&game->map[old.y][old.x], '0', 1);
	return (1);
}

void	ft_move(int dir, t_game *game, t_player *temp)
{
	t_vector	nw;

	if (temp && !ft_checkmvtogh(game, dir, temp))
	{
		if (dir == N && ft_strchr("0CE",
				game->map[temp->pos.y - 1][temp->pos.x]))
			nw = ft_newvector(temp->pos.x, temp->pos.y - 1);
		else if (dir == S && ft_strchr("0CE",
				game->map[temp->pos.y + 1][temp->pos.x]))
			nw = ft_newvector(temp->pos.x, temp->pos.y + 1);
		else if (dir == E && ft_strchr("0CE",
				game->map[temp->pos.y][temp->pos.x + 1]))
			nw = ft_newvector(temp->pos.x + 1, temp->pos.y);
		else if (dir == W && ft_strchr("0CE",
				game->map[temp->pos.y][temp->pos.x - 1]))
			nw = ft_newvector(temp->pos.x - 1, temp->pos.y);
		else
			nw = ft_newvector(0, 0);
		if (game->map[nw.y][nw.x] == 'C')
			game->lay->n_collect--;
		if (nw.x && nw.y)
			ft_swap_tile(ft_newvector(temp->pos.x, temp->pos.y), nw, game);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:13:38 by amine             #+#    #+#             */
/*   Updated: 2023/07/16 18:43:08 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_redraw_pac(t_game *game)
{
	t_player	*pl;

	pl = game->pl;
	while (pl)
	{
		if (pl->win_pos.x < pl->pos.x * SIZE && pl->moving)
			pl->win_pos.x++;
		if (pl->win_pos.x > pl->pos.x * SIZE && pl->moving)
			pl->win_pos.x--;
		if (pl->win_pos.y < pl->pos.y * SIZE && pl->moving)
			pl->win_pos.y++;
		if (pl->win_pos.y > pl->pos.y * SIZE && pl->moving)
			pl->win_pos.y--;
		if (pl->win_pos.x == pl->pos.x * SIZE
			&& pl->win_pos.y == pl->pos.y * SIZE)
			pl->moving = 0;
		pl = pl->next;
	}
	ft_put_pacman(game);
}

void	ft_redraw_gh(t_game *game)
{
	t_player	*pl;

	pl = game->gh;
	while (pl)
	{
		if (pl->win_pos.x < pl->pos.x * SIZE && pl->moving)
			pl->win_pos.x++;
		if (pl->win_pos.x > pl->pos.x * SIZE && pl->moving)
			pl->win_pos.x--;
		if (pl->win_pos.y < pl->pos.y * SIZE && pl->moving)
			pl->win_pos.y++;
		if (pl->win_pos.y > pl->pos.y * SIZE && pl->moving)
			pl->win_pos.y--;
		if (pl->win_pos.x == pl->pos.x * SIZE
			&& pl->win_pos.y == pl->pos.y * SIZE)
		{
			ft_redraw_pacfood(game, pl);
			ft_redraw_exit(game, pl);
			pl->moving = 0;
		}
		pl = pl->next;
	}
	ft_put_ghosts(game);
}

void	ft_redraw_pacfood(t_game *game, t_player *pl)
{
	if (pl->dir == N && game->map[pl->pos.y + 1][pl->pos.x] == 'C')
		mlx_put_image_to_window(game->id, game->w_id, game->sprites.pacfood,
			pl->pos.x * SIZE, (pl->pos.y + 1) * SIZE);
	if (pl->dir == S && game->map[pl->pos.y - 1][pl->pos.x] == 'C')
		mlx_put_image_to_window(game->id, game->w_id, game->sprites.pacfood,
			pl->pos.x * SIZE, (pl->pos.y - 1) * SIZE);
	if (pl->dir == E && game->map[pl->pos.y][pl->pos.x - 1] == 'C')
		mlx_put_image_to_window(game->id, game->w_id, game->sprites.pacfood,
			(pl->pos.x - 1) * SIZE, pl->pos.y * SIZE);
	if (pl->dir == W && game->map[pl->pos.y][pl->pos.x + 1] == 'C')
		mlx_put_image_to_window(game->id, game->w_id, game->sprites.pacfood,
			(pl->pos.x + 1) * SIZE, pl->pos.y * SIZE);
}

void	ft_redraw_exit(t_game *game, t_player *pl)
{
	if (pl->dir == N && game->map[pl->pos.y + 1][pl->pos.x] == 'E')
		mlx_put_image_to_window(game->id, game->w_id, game->sprites.portal,
			pl->pos.x * SIZE, (pl->pos.y + 1) * SIZE);
	if (pl->dir == S && game->map[pl->pos.y - 1][pl->pos.x] == 'E')
		mlx_put_image_to_window(game->id, game->w_id, game->sprites.portal,
			pl->pos.x * SIZE, (pl->pos.y - 1) * SIZE);
	if (pl->dir == E && game->map[pl->pos.y][pl->pos.x - 1] == 'E')
		mlx_put_image_to_window(game->id, game->w_id, game->sprites.portal,
			(pl->pos.x - 1) * SIZE, pl->pos.y * SIZE);
	if (pl->dir == W && game->map[pl->pos.y][pl->pos.x + 1] == 'E')
		mlx_put_image_to_window(game->id, game->w_id, game->sprites.portal,
			(pl->pos.x + 1) * SIZE, pl->pos.y * SIZE);
}

void	ft_put_stopped(t_game *game, t_player *pl)
{
	if (pl->dir == N)
		mlx_put_image_to_window(game->id, game->w_id,
			pl->sprites.up_bak->content,
			pl->pos.x * SIZE, pl->pos.y * SIZE);
	if (pl->dir == S)
		mlx_put_image_to_window(game->id, game->w_id,
			pl->sprites.down_bak->content,
			pl->pos.x * SIZE, pl->pos.y * SIZE);
	if (pl->dir == E)
		mlx_put_image_to_window(game->id, game->w_id,
			pl->sprites.right_bak->content,
			pl->pos.x * SIZE, pl->pos.y * SIZE);
	if (pl->dir == W)
		mlx_put_image_to_window(game->id, game->w_id,
			pl->sprites.left_bak->content,
			pl->pos.x * SIZE, pl->pos.y * SIZE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:24:06 by amine             #+#    #+#             */
/*   Updated: 2023/07/16 18:35:34 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_anim_north(t_game *game, t_player *pl)
{
	t_player	*temp;

	temp = pl;
	if (!(game->n_frames % (((game->panic_mode * 7 + game->g_rate)
					+ game->g_rate) / 7)))
		temp->sprites.up = temp->sprites.up->next;
	if (!temp->sprites.up)
		temp->sprites.up = temp->sprites.up_bak;
	mlx_put_image_to_window(game->id, game->w_id, temp->sprites.up->content,
		temp->win_pos.x, temp->win_pos.y);
}

void	ft_anim_south(t_game *game, t_player *pl)
{
	t_player	*temp;

	temp = pl;
	if (!(game->n_frames % (((game->panic_mode * 7 + game->g_rate)
					+ game->g_rate) / 7)))
		temp->sprites.down = temp->sprites.down->next;
	if (!temp->sprites.down)
		temp->sprites.down = temp->sprites.down_bak;
	mlx_put_image_to_window(game->id, game->w_id, temp->sprites.down->content,
		temp->win_pos.x, temp->win_pos.y);
}

void	ft_anim_east(t_game *game, t_player *pl)
{
	t_player	*temp;

	temp = pl;
	if (!(game->n_frames % (((game->panic_mode * 7 + game->g_rate)
					+ game->g_rate) / 7)))
		temp->sprites.right = temp->sprites.right->next;
	if (!temp->sprites.right)
		temp->sprites.right = temp->sprites.right_bak;
	mlx_put_image_to_window(game->id, game->w_id, temp->sprites.right->content,
		temp->win_pos.x, temp->win_pos.y);
}

void	ft_anim_west(t_game *game, t_player *pl)
{
	t_player	*temp;

	temp = pl;
	if (!(game->n_frames % (((game->panic_mode * 7 + game->g_rate)
					+ game->g_rate) / 7)))
		temp->sprites.left = temp->sprites.left->next;
	if (!temp->sprites.left)
		temp->sprites.left = temp->sprites.left_bak;
	mlx_put_image_to_window(game->id, game->w_id, temp->sprites.left->content,
		temp->win_pos.x, temp->win_pos.y);
}

void	ft_anim_panic(t_game *game, t_player *pl)
{
	t_player	*temp;

	temp = pl;
	if (!(game->n_frames % (game->g_rate / 3)))
		temp->sprites.panic = temp->sprites.panic->next;
	if (!temp->sprites.panic)
		temp->sprites.panic = temp->sprites.panic_bak;
	mlx_put_image_to_window(game->id, game->w_id, temp->sprites.panic->content,
		temp->win_pos.x, temp->win_pos.y);
}

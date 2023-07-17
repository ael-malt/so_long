/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:25:17 by ael-malt          #+#    #+#             */
/*   Updated: 2023/07/16 18:28:42 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_free_singlepl(t_game *game, t_player *pl)
{
	free_animation(game, pl->sprites.up_bak);
	free_animation(game, pl->sprites.down_bak);
	free_animation(game, pl->sprites.left_bak);
	free_animation(game, pl->sprites.right_bak);
}

void	free_players(t_game *game)
{
	t_player	*ghost;
	t_player	*pacman;

	ghost = game->gh;
	pacman = game->pl;
	while (ghost)
	{
		free_animation(game, ghost->sprites.up_bak);
		free_animation(game, ghost->sprites.down_bak);
		free_animation(game, ghost->sprites.left_bak);
		free_animation(game, ghost->sprites.right_bak);
		free_animation(game, ghost->sprites.panic_bak);
		ghost = ghost->next;
	}
	while (pacman)
	{
		free_animation(game, pacman->sprites.up_bak);
		free_animation(game, pacman->sprites.down_bak);
		free_animation(game, pacman->sprites.left_bak);
		free_animation(game, pacman->sprites.right_bak);
		pacman = pacman->next;
	}
}

int	free_sprites(t_game *game)
{
	mlx_destroy_image(game->id, game->sprites.wall);
	mlx_destroy_image(game->id, game->sprites.pacfood);
	mlx_destroy_image(game->id, game->sprites.portal);
	mlx_destroy_image(game->id, game->sprites.logo);
	mlx_destroy_image(game->id, game->sprites.pacman);
	mlx_destroy_image(game->id, game->sprites.black);
	free_players(game);
	free_fonts(game);
	free_animation(game, game->sprites.pac_dying_bak);
	return (0);
}

t_sprite	ft_initsprites(t_game *game)
{
	int			size;

	size = SIZE;
	game->sprites.wall = mlx_xpm_file_to_image(game->id,
			"sprites/Other/Walls/wall.xpm", &size, &size);
	game->sprites.pacfood = mlx_xpm_file_to_image(game->id,
			"sprites/Other/Pacdots/pacdot_food.xpm", &size, &size);
	game->sprites.portal = mlx_xpm_file_to_image(game->id,
			"sprites/Other/Portal/portal.xpm", &size, &size);
	game->sprites.logo = mlx_xpm_file_to_image(game->id,
			"sprites/Other/Logo/logo.xpm", &size, &size);
	game->sprites.pacman = mlx_xpm_file_to_image(game->id,
			"sprites/Pac-Man/pac_closed.xpm", &size, &size);
	game->sprites.black = mlx_xpm_file_to_image(game->id,
			"sprites/Other/Walls/black.xpm", &size, &size);
	game->sprites.pac_dying = ft_load_pacdeath(game);
	game->sprites.score_font = ft_load_score_font(game);
	game->sprites.pac_dying_bak = game->sprites.pac_dying;
	return (game->sprites);
}

void	ft_put_map(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->id, game->w_id, game->sprites.wall,
			x * SIZE, y * SIZE);
	if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->id, game->w_id, game->sprites.portal,
			x * SIZE, y * SIZE);
	if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->id, game->w_id, game->sprites.pacfood,
			x * SIZE, y * SIZE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:44:35 by ael-malt          #+#    #+#             */
/*   Updated: 2023/07/16 18:43:40 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_update_score(t_game *game)
{
	int	i;
	int	score;
	int	digit;

	i = 0;
	score = game->n_moves;
	while (i < 4)
	{
		digit = score % 10;
		score /= 10;
		mlx_put_image_to_window(game->id, game->w_id,
			game->sprites.score_font.black,
			game->width / 2 + 10 - 12 * i, game->height - 67);
		ft_put_font(game, digit, i);
		i++;
	}
}

t_font	ft_load_score_font(t_game *game)
{
	int	size;

	game->sprites.score_font.zero = mlx_xpm_file_to_image(game->id,
			"sprites/Other/Fonts/0.xpm", &size, &size);
	game->sprites.score_font.one = mlx_xpm_file_to_image(game->id,
			"sprites/Other/Fonts/1.xpm", &size, &size);
	game->sprites.score_font.two = mlx_xpm_file_to_image(game->id,
			"sprites/Other/Fonts/2.xpm", &size, &size);
	game->sprites.score_font.three = mlx_xpm_file_to_image(game->id,
			"sprites/Other/Fonts/3.xpm", &size, &size);
	game->sprites.score_font.four = mlx_xpm_file_to_image(game->id,
			"sprites/Other/Fonts/4.xpm", &size, &size);
	game->sprites.score_font.five = mlx_xpm_file_to_image(game->id,
			"sprites/Other/Fonts/5.xpm", &size, &size);
	game->sprites.score_font.six = mlx_xpm_file_to_image(game->id,
			"sprites/Other/Fonts/6.xpm", &size, &size);
	game->sprites.score_font.seven = mlx_xpm_file_to_image(game->id,
			"sprites/Other/Fonts/7.xpm", &size, &size);
	game->sprites.score_font.eight = mlx_xpm_file_to_image(game->id,
			"sprites/Other/Fonts/8.xpm", &size, &size);
	game->sprites.score_font.nine = mlx_xpm_file_to_image(game->id,
			"sprites/Other/Fonts/9.xpm", &size, &size);
	game->sprites.score_font.black = mlx_xpm_file_to_image(game->id,
			"sprites/Other/Fonts/black.xpm", &size, &size);
	return (game->sprites.score_font);
}

void	ft_put_font(t_game *game, int digit, int i)
{
	void	*font;

	font = NULL;
	if (digit == 0)
		font = game->sprites.score_font.zero;
	if (digit == 1)
		font = game->sprites.score_font.one;
	if (digit == 2)
		font = game->sprites.score_font.two;
	if (digit == 3)
		font = game->sprites.score_font.three;
	if (digit == 4)
		font = game->sprites.score_font.four;
	if (digit == 5)
		font = game->sprites.score_font.five;
	if (digit == 6)
		font = game->sprites.score_font.six;
	if (digit == 7)
		font = game->sprites.score_font.seven;
	if (digit == 8)
		font = game->sprites.score_font.eight;
	if (digit == 9)
		font = game->sprites.score_font.nine;
	mlx_put_image_to_window(game->id, game->w_id, font,
		game->width / 2 + 10 - 12 * i, game->height - 67);
}

void	free_fonts(t_game *game)
{
	mlx_destroy_image(game->id, game->sprites.score_font.black);
	mlx_destroy_image(game->id, game->sprites.score_font.zero);
	mlx_destroy_image(game->id, game->sprites.score_font.one);
	mlx_destroy_image(game->id, game->sprites.score_font.two);
	mlx_destroy_image(game->id, game->sprites.score_font.three);
	mlx_destroy_image(game->id, game->sprites.score_font.four);
	mlx_destroy_image(game->id, game->sprites.score_font.five);
	mlx_destroy_image(game->id, game->sprites.score_font.six);
	mlx_destroy_image(game->id, game->sprites.score_font.seven);
	mlx_destroy_image(game->id, game->sprites.score_font.eight);
	mlx_destroy_image(game->id, game->sprites.score_font.nine);
}

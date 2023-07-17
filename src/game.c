/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-malt <ael-malt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:24:12 by amine             #+#    #+#             */
/*   Updated: 2023/07/17 16:29:20 by ael-malt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*
	Key_ids
	Q:			98
	ESC:		XK_Escape
	R:			111
	W:			233
	A:			97
	S:			117
	D:			105
	Arrow Up:	XK_Up
	Arrow L:	XK_Left
	Arrow Down:	XK_Down
	Arrow R:	XK_Right
*/

int	key_hook(int key, t_game *game)
{
	if ((key == 98 || key == XK_Escape) && !game->pac_dying)
	{
		ft_printf("\n\033[0;91mYou quit the game early!\033[0;39m\n\n");
		end_game(game);
	}
	if (key == 111 && !game->pac_dying)
		ft_reset(game);
	if ((key == XK_Up || key == 233) && game->next_dir != N
		&& !game->pac_dying)
		ft_newdirection(game, N);
	if ((key == XK_Down || key == 117) && game->next_dir != S
		&& !game->pac_dying)
		ft_newdirection(game, S);
	if ((key == XK_Right || key == 105) && game->next_dir != E
		&& !game->pac_dying)
		ft_newdirection(game, E);
	if ((key == XK_Left || key == 97) && game->next_dir != W
		&& !game->pac_dying)
		ft_newdirection(game, W);
	return (0);
}

int	end_game(t_game *game)
{
	if (game->map)
		ft_free_matrix(&game->map);
	if (game->map_bak)
		ft_free_matrix(&game->map_bak);
	free_sprites(game);
	ft_free_playerlist(game);
	ft_printf("\033[0;92mGame Finished!\n\033[0;94mTotal Moves: %d\n\n\033[0;39m",
		game->n_moves);
	mlx_clear_window(game->id, game->w_id);
	mlx_destroy_window(game->id, game->w_id);
	mlx_destroy_display(game->id);
	free(game->id);
	exit(0);
	return (0);
}

void	init_game(char **map, t_lay lay)
{
	t_game	game;

	game.lay_bak = lay;
	game.n_collect_bak = lay.n_collect;
	game.map_bak = ft_dup_matrix(map);
	game.id = mlx_init();
	game.w_id = mlx_new_window(game.id, lay.n_col * SIZE,
			lay.n_row * SIZE + 80, "Pac-Man");
	ft_newgame(&game, map, &lay);
}

void	ft_newgame(t_game *game, char **m, t_lay *lay)
{
	game->n_frames = 1;
	game->n_moves = 0;
	game->width = lay->n_col * SIZE;
	game->height = lay->n_row * SIZE + 80;
	game->lay = lay;
	game->map = m;
	game->sprites = ft_initsprites(game);
	game->pl = NULL;
	game->gh = NULL;
	ft_playerlist(m, game);
	game->next_dir = 0;
	ft_load_ghosts(game);
	ft_load_pacmans(game);
	game->pac_dying = 0;
	game->panic_mode = 0;
	game->g_rate = 150;
	game->redraw = 1;
	mlx_loop_hook(game->id, ft_update, (void *)game);
	mlx_hook(game->w_id, 17, 0, end_game, (void *)game);
	mlx_key_hook(game->w_id, key_hook, (void *)game);
	mlx_loop(game->id);
}

void	ft_check_game(t_game *game)
{
	if (game->lay_bak.n_collect / 4 + 1 >= game->lay->n_collect
		&& game->lay->n_gh)
	{
		if (!game->panic_mode)
			game->g_rate -= game->g_rate / 3;
		game->panic_mode = 1;
	}
	if (!(game->n_frames % (game->g_rate + (game->g_rate / 13))))
		ft_redraw_gh(game);
	if (!(game->n_frames % game->g_rate) && !game->pac_dying)
		ft_redraw_pac(game);
	if (game->pl->dir != ST && !game->pac_dying)
		ft_update_ghosts(game);
	if (game->next_dir)
		ft_next_dir(game);
	if (game->pac_dying && !(game->n_frames % (10 * game->g_rate)))
		ft_anim_pacdeath(game);
	if (!game->lay->n_collect && !game->lay->n_pl && !game->pac_dying)
	{
		ft_printf("\033[0;92mCONGRATULATIONS, YOU WIN!\033[0;39m\n\n");
		end_game(game);
	}
}

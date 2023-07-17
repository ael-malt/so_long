/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:35:35 by ael-malt          #+#    #+#             */
/*   Updated: 2023/07/16 18:39:43 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_anim_pacdeath(t_game *game)
{
	t_player	*temp_pl;

	temp_pl = game->pl;
	while (temp_pl)
	{
		mlx_put_image_to_window(game->id, game->w_id, game->sprites.black,
			temp_pl->win_pos.x, temp_pl->win_pos.y);
		mlx_put_image_to_window(game->id, game->w_id,
			game->sprites.pac_dying->content, temp_pl->win_pos.x,
			temp_pl->win_pos.y);
		temp_pl = temp_pl->next;
	}
	game->sprites.pac_dying = game->sprites.pac_dying->next;
	if (!game->sprites.pac_dying)
	{
		ft_printf("\n\033[0;91mGAME OVER\nBetter luck next time!\033[0;39m\n\n");
		end_game(game);
	}
}

t_list	*ft_load_pacdeath(t_game *game)
{
	t_list	*pacdeath;
	char	*s;
	char	c;
	int		size;

	pacdeath = NULL;
	s = ft_substr("sprites/Pac-Man/Dying/pacman_dying1.xpm", 0, 39);
	c = '0';
	while (c++ < '8' + 1)
	{
		ft_memset(&s[34], c, 1);
		ft_lstadd_back(&pacdeath,
			ft_lstnew(mlx_xpm_file_to_image(game->id, s, &size, &size)));
	}
	free(s);
	ft_lstadd_back(&pacdeath, ft_lstnew(mlx_xpm_file_to_image(game->id,
				"sprites/Pac-Man/Dying/pacman_dying10.xpm", &size, &size)));
	while (c-- > '7')
	{
		ft_lstadd_back(&pacdeath, ft_lstnew(mlx_xpm_file_to_image(game->id,
					"sprites/Other/Walls/black.xpm", &size, &size)));
		ft_lstadd_back(&pacdeath, ft_lstnew(mlx_xpm_file_to_image(game->id,
					"sprites/Pac-Man/Dying/pacman_woosh.xpm", &size, &size)));
	}
	return (pacdeath);
}

void	free_animation(t_game *game, t_list *start)
{
	t_list		*temp;

	temp = NULL;
	while (start)
	{
		temp = start;
		start = start->next;
		if (game)
			mlx_destroy_image(game->id, temp->content);
		free(temp);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playerlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:48:07 by ael-malt          #+#    #+#             */
/*   Updated: 2023/07/16 18:34:17 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_free_playerlist(t_game *game)
{
	t_player	*temp;

	while (game->pl)
	{
		temp = game->pl;
		game->pl = game->pl->next;
		free(temp);
		temp = NULL;
	}
	while (game->gh)
	{
		temp = game->gh;
		game->gh = game->gh->next;
		free(temp);
		temp = NULL;
	}
}

int	ft_deletefirst_plr(t_game *game)
{
	t_player	*head;

	head = game->pl;
	if (head->next)
		game->pl = head->next;
	else
		game->pl = NULL;
	free(head);
	head = NULL;
	return (1);
}

int	ft_deletelast_plr(t_game *game)
{
	t_player	*head;

	head = game->pl;
	while (head->next->next)
		head = head->next;
	free(head->next);
	head->next = NULL;
	return (1);
}

void	ft_playerlist(char **map, t_game *game)
{
	int			x;
	int			y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				ft_plradd_back(&game->pl, ft_plrnew(ft_newvector(x, y)));
			if (map[y][x] == 'G')
				ft_plradd_back(&game->gh, ft_plrnew(ft_newvector(x, y)));
			x++;
		}
		y++;
	}
}

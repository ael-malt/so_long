/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:21:34 by ael-malt          #+#    #+#             */
/*   Updated: 2023/07/16 18:42:39 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_player	*ft_plrnew(t_vector pos)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->pos = pos;
	player->win_pos = ft_newvector(pos.x * SIZE, pos.y * SIZE);
	player->moving = 0;
	player->dir = ST;
	player->next = NULL;
	return (player);
}

void	ft_plradd_back(t_player **lst, t_player *newnode)
{
	t_player	*start;

	start = *lst;
	if (*lst)
	{
		while (start->next)
			start = start->next;
		start->next = newnode;
	}
	else
		*lst = newnode;
}

int	ft_delete_player(t_game *game, t_vector old)
{
	t_player	*temp;
	t_player	*prev;

	temp = game->pl;
	prev = NULL;
	game->lay->n_pl--;
	while (temp)
	{
		if (temp->pos.x == old.x && temp->pos.y == old.y)
		{
			ft_free_singlepl(game, temp);
			if (!prev)
				return (ft_deletefirst_plr(game));
			if (prev && !temp->next)
				return (ft_deletelast_plr(game));
			prev->next = temp->next;
			free(temp);
			temp = NULL;
			return (1);
		}
		prev = temp;
		temp = temp->next;
	}
	return (1);
}

int	ft_checkmvtogh(t_game *game, int d, t_player *pl)
{
	t_player	*gh;

	gh = game->gh;
	while (gh)
	{
		if (d == N && pl->pos.y - 1 == gh->pos.y && pl->pos.x == gh->pos.x)
			game->pac_dying = 1;
		if (d == S && pl->pos.y + 1 == gh->pos.y && pl->pos.x == gh->pos.x)
			game->pac_dying = 1;
		if (d == E && pl->pos.y == gh->pos.y && pl->pos.x + 1 == gh->pos.x)
			game->pac_dying = 1;
		if (d == W && pl->pos.y == gh->pos.y && pl->pos.x - 1 == gh->pos.x)
			game->pac_dying = 1;
		if (pl->pos.y == gh->pos.y && pl->pos.x == gh->pos.x)
			game->pac_dying = 1;
		gh = gh->next;
	}
	return (game->pac_dying);
}

int	ft_update(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	game->n_frames++;
	ft_check_game(game);
	if (game->redraw)
	{
		ft_put_ghosts(game);
		mlx_put_image_to_window(game->id, game->w_id, game->sprites.logo,
			(game->width - 131) / 2, game->height - 42);
		ft_update_score(game);
		while (game->map[y])
		{
			x = 0;
			while (game->map[y][x])
			{
				ft_put_map(game, x, y);
				x++;
			}
			y++;
		}
		game->redraw = 0;
	}
	return (0);
}

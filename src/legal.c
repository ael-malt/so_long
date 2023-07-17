/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-malt <ael-malt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:57:41 by amine             #+#    #+#             */
/*   Updated: 2023/07/17 11:57:41 by ael-malt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_update_legal(t_game *game, t_player *gh)
{
	gh->legal.north = (!ft_strchr("1G", game->map[gh->pos.y - 1][gh->pos.x])
			&& !ft_findghost(game->gh, ft_newvector(gh->pos.x, gh->pos.y - 1)));
	gh->legal.south = (!ft_strchr("1G", game->map[gh->pos.y + 1][gh->pos.x])
			&& !ft_findghost(game->gh, ft_newvector(gh->pos.x, gh->pos.y + 1)));
	gh->legal.east = (!ft_strchr("1G", game->map[gh->pos.y][gh->pos.x + 1])
			&& !ft_findghost(game->gh, ft_newvector(gh->pos.x + 1, gh->pos.y)));
	gh->legal.west = (!ft_strchr("1G", game->map[gh->pos.y][gh->pos.x - 1])
			&& !ft_findghost(game->gh, ft_newvector(gh->pos.x - 1, gh->pos.y)));
}

void	ft_restrict_legal(t_player *ghost)
{
	if (ft_legal_len(ghost) != 1)
	{
		if (ghost->dir == N)
			ghost->legal.south = 0;
		if (ghost->dir == S)
			ghost->legal.north = 0;
		if (ghost->dir == E)
			ghost->legal.west = 0;
		if (ghost->dir == W)
			ghost->legal.east = 0;
	}
}

int	ft_legal_len(t_player *player)
{
	int	count;

	count = 0;
	count += player->legal.north;
	count += player->legal.south;
	count += player->legal.east;
	count += player->legal.west;
	return (count);
}

int	ft_in_legal(t_player *player, int dir)
{
	if (dir == N && player->legal.north)
		return (1);
	if (dir == S && player->legal.south)
		return (1);
	if (dir == E && player->legal.east)
		return (1);
	if (dir == W && player->legal.west)
		return (1);
	if (dir == ST)
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-malt <ael-malt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:23:28 by ael-malt          #+#    #+#             */
/*   Updated: 2023/07/17 15:54:03 by ael-malt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	error_msg(char *msg, char **map_str)
{
	if (map_str)
		free(*map_str);
	ft_printf("\033[0;31mError:\n%s\033[0;39m\n", msg);
	exit(0);
	return (0);
}

t_err	ft_newmap_error(void)
{
	t_err	map_err;

	map_err.inv_borders = 0;
	map_err.inv_char = 0;
	map_err.inv_n_exits = 0;
	map_err.inv_n_collect = 0;
	map_err.inv_rowlen = 0;
	map_err.inv_n_players = 0;
	map_err.inv_n_ghosts = 0;
	map_err.inv_path = 0;
	return (map_err);
}

void	ft_readlayout(int fd, t_err *map_err, t_lay *lay, char **map_str)
{
	char		*line;
	char		*last_line;

	line = NULL;
	last_line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			if (!lay->n_col)
				error_msg("Map is empty", NULL);
			else
				ft_checklayout(last_line, map_err, lay, 1);
			free(last_line);
			break ;
		}
		free(last_line);
		ft_checklayout(line, map_err, lay, !lay->n_row);
		last_line = ft_substr(line, 0, ft_strlen(line));
		*map_str = ft_strenlarge(*map_str, line);
		lay->n_row++;
	}
}

void	ft_checklayout(char *l, t_err *map_err, t_lay *lay, int is_last)
{
	if (!lay->n_col)
		lay->n_col = ft_strlen(l) - 1;
	if (lay->n_col && ((lay->n_col != (int)ft_strlen(l) - 1 && ft_strchr(l, \
		'\n')) || (lay->n_col != (int)ft_strlen(l) && !ft_strchr(l, '\n'))))
		map_err->inv_rowlen = 1;
	if (l[0] != '1' || l[lay->n_col - 1] != '1'
		|| (ft_countchar(l, '1') != lay->n_col && is_last))
			map_err->inv_borders = 1;
	lay->n_exit += ft_countchar(l, 'E');
	lay->n_pl += ft_countchar(l, 'P');
	lay->n_gh += ft_countchar(l, 'G');
	lay->n_collect += ft_countchar(l, 'C');
	if (lay->n_exit != 1)
		map_err->inv_n_exits = 1;
	else
		map_err->inv_n_exits = 0;
	if (lay->n_pl != 1)
		map_err->inv_n_players = 1;
	else
		map_err->inv_n_players = 0;
	map_err->inv_n_collect = lay->n_collect < 1;
	while (l++ && *l)
		if (!ft_strchr("01CEPG\n", *l))
			map_err->inv_char = 1;
}
	// map_err->inv_n_exits = lay->n_exit < 1;
	// map_err->inv_n_players = lay->n_pl < 1;
	// map_err->inv_n_collect = lay->n_collect < 1;

int	ft_print_map_error(t_err *map_err, char **map_str)
{
	if (map_err->inv_rowlen)
		error_msg("Map must be rectangular!", map_str);
	if (map_err->inv_borders)
		error_msg("Map must be surrounded by walls!", map_str);
	if (map_err->inv_char)
		error_msg("Unexpected character(s) in map!", map_str);
	if (map_err->inv_n_exits)
		error_msg("Invalid amount of exits!", map_str);
	if (map_err->inv_n_players)
		error_msg("Invalid amount of players!", map_str);
	if (map_err->inv_n_collect)
		error_msg("There should be at least one collectible!", map_str);
	return (0);
}

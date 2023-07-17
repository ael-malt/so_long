/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-malt <ael-malt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:28:26 by amine             #+#    #+#             */
/*   Updated: 2023/07/17 17:41:53 by ael-malt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_lay	ft_newlayout(void)
{
	t_lay	lay;

	lay.n_row = 0;
	lay.n_col = 0;
	lay.n_exit = 0;
	lay.n_pl = 0;
	lay.n_gh = 0;
	lay.n_collect = 0;
	return (lay);
}

void	find_player(char **map, int *i, int *j)
{
	int	x;
	int	y; 
	x = 0;	
	ft_printf("\n");
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'P')
			{
				ft_printf("%c", map[x][y]);
				*i = x;
				*j = y;
			}
			y++;
		}
		ft_printf("\n");
		x++;
	}
}

void	print_map(char **map)
{
	int	x;
	int	y; 
	x = 0;	
	ft_printf("\n");
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			ft_printf("%c", map[x][y]);
			y++;
		}
		ft_printf("\n");
		x++;
	}
}
void	ft_path(char **map, t_lay *lay, int i, int j)
{
	if(lay->n_collect == 0 && lay->n_exit == 0)
	return ;
	if (map[i][j] == 'C')
		lay->n_collect--;
	if (map[i][j] == 'E')
	{
		lay->n_exit--;
	}
	map[i][j] = '1';
	if (map[i + 1][j] != '1' && map[i + 1][j] != '\0' )
		ft_path(map, lay , i + 1, j);
	if (map[i][j + 1] != '1' && map[i][j + 1] != '\0')
		ft_path(map, lay , i, j + 1);
	if (map[i - 1][j] != '1' && map[i - 1][j] != '\0')
		ft_path(map, lay , i - 1, j);
	if (map[i][j - 1] != '1' && map[i][j - 1] != '\0')
		ft_path(map, lay , i, j - 1);
	return ;
}

int	check_map_path(char **map, t_lay *lay)
{
	char	**map_bak;
	int		i;
	int		j;
	t_lay new_lay = ft_newlayout();

	new_lay.n_collect = lay->n_collect;
	new_lay.n_exit = lay->n_exit;

	map_bak = ft_dup_matrix(map);
	find_player(map_bak, &i, &j);
	
	ft_path(map_bak, &new_lay, i, j);
	ft_printf("n_collect: %d\n", new_lay.n_exit);
	ft_printf("n_exit: %d\n", new_lay.n_collect);
	if (new_lay.n_collect || new_lay.n_exit)
	{
		print_map(map_bak);
		free(*map_bak);
		error_msg("There is no path to the exit!", map);
	}


	return (0);
}

char	**check_map(int fd, t_lay *lay)
{
	char	*map_str;
	char	**map;
	t_err	map_err;

	map_str = NULL;
	map = NULL;
	map_err = ft_newmap_error();
	*lay = ft_newlayout();
	ft_readlayout(fd, &map_err, lay, &map_str);
	ft_print_map_error(&map_err, &map_str);
	map = ft_split(map_str, '\n');
	free(map_str);
	if (!map)
		error_msg("Memory allocation error!", NULL);
	return (map);
}

char	**check_params(int argc, char **argv, t_lay *lay)
{
	int		fd;

	if (argc != 2)
		error_msg("Invalid amount of arguments! \
			Try having a single argument", NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_msg("File not found!", NULL);
	if (ft_strrncmp(argv[1], ".ber", 4))
		error_msg("Invalid file type! Try using a \".ber\" file", NULL);
	return (check_map(fd, lay));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-malt <ael-malt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:23:28 by ael-malt          #+#    #+#             */
/*   Updated: 2023/07/17 16:53:30 by ael-malt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	char	**map;
	t_lay	lay;

	map = check_params(argc, argv, &lay);
	// ft_printf("\n\n\n%c\n\n\n", map[5][10]);
	check_map_path(map, &lay);
	init_game(map, lay);
	return (0);
}

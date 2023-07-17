/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:14:43 by ael-malt          #+#    #+#             */
/*   Updated: 2023/07/13 19:02:49 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_isdigit(int c)

{
	if (c >= '0' && c <= '9')
		return (2048);
	return (0);
}

// int main(int argc, char *argv[])
// {
// 	(void) argc;
//	ft_printf("ft_isdigit: %d\n", ft_isdigit(argv[1][0]));
//	ft_printf("isdigit: %d\n", isdigit(argv[1][0]));
// 	return 0;
// }

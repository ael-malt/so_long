/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:32:03 by ael-malt          #+#    #+#             */
/*   Updated: 2023/07/13 19:02:49 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (8);
	return (0);
}

// int main(int argc, char *argv[])
// {
// 	(void) argc;
//	ft_printf("ft_isalnum: %d\n", ft_isalnum(argv[1][0]));
//	ft_printf("isalnum: %d\n", isalnum(argv[1][0]));
// 	return 0;
// }ezzyy

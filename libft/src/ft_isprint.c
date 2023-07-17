/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:02:10 by ael-malt          #+#    #+#             */
/*   Updated: 2023/07/13 19:02:49 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

// int main()
// {
//	ft_printf("ft_isprint: %d\n", ft_isprint('\0'));
//	ft_printf("isprint: %d\n", isprint('\0'));
//	ft_printf("ft_isprint: %d\n", ft_isprint(' '));
//	ft_printf("isprint: %d\n", isprint(' '));
// 	return 0;
// }

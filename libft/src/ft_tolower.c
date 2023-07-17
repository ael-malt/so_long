/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:37:24 by ael-malt          #+#    #+#             */
/*   Updated: 2023/07/13 19:02:49 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ' ');
	return (c);
}

// int main()
// {
//	ft_printf("ft_tolower: %c\n", ft_tolower('A'));
//	ft_printf("tolower: %c\n\n", tolower('A'));
//	ft_printf("ft_tolower: %c\n", ft_tolower('\\'));
//	ft_printf("tolower: %c\n", tolower('\\'));
// 	return 0;
// }

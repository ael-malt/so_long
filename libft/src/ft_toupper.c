/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:48:10 by ael-malt          #+#    #+#             */
/*   Updated: 2023/07/13 19:02:49 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - ' ');
	return (c);
}

// int main()
// {
//	ft_printf("ft_toupper: %c\n", ft_toupper('A'));
//	ft_printf("toupper: %c\n\n", toupper('A'));
//	ft_printf("ft_toupper: %c\n", ft_toupper('\\'));
//	ft_printf("toupper: %c\n", toupper('\\'));
// 	return 0;
// }

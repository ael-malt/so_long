/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:35:32 by ael-malt          #+#    #+#             */
/*   Updated: 2023/07/13 19:02:49 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (unsigned char )c;
		i++;
	}
	return (s);
}

// int main()
// {
// 	char str[50] = "GeeksForGeeks is for programming geeks.";
// 	char str1[50] = "GeeksForGeeks is for programming geeks.";
//	ft_printf("Before    memset(): %s\n", str);
//	ft_printf("Before ft_memset(): %s\n\n", str1);

// // 	memset(str + 13, '.', 8*sizeof(char));
// 	ft_memset(str1 + 13, '.', 8*sizeof(char));

//	ft_printf("After    memset():  %s\n", str);
//	ft_printf("After ft_memset():  %s\n", str1);

// 	return 0;
// }

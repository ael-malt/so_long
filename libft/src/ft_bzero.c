/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:50:40 by ael-malt          #+#    #+#             */
/*   Updated: 2023/07/13 19:02:49 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;
	size_t	i;

	if (!n)
		return ;
	i = 0;
	ptr = s;
	while (i < n)
	{
		*(ptr + i) = '\0';
		i++;
	}
}

// int main()
// {
// 	char str[50] = "GeeksForGeeks is for programming geeks.";
// 	char str1[50] = "GeeksForGeeks is for programming geeks.";
//	ft_printf("Before    bzero(): %s\n", str);
//	ft_printf("Before ft_bzero(): %s\n\n", str1);

// // 	bzero(str, 8*sizeof(char));
// 	ft_bzero(str1, 8*sizeof(char));

//	ft_printf("After    bzero():  %s\n", str);
//	ft_printf("After ft_bzero():  %s\n", str1);

// 	return 0;
// }

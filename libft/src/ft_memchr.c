/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:59:42 by ael-malt          #+#    #+#             */
/*   Updated: 2023/07/13 19:02:49 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char) c)
		{
			return (&((unsigned char *)s)[i]);
		}
		i++;
	}
	return (0);
}

// int main()
// {
// 	char str[50] = "GeeksForGeeks is for programming geeks.";
// 	char str1[50] = "GeeksForGeeks is for programming geeks.";
// 	char *ret;
// 	char *ret1;

//	ft_printf("Before    memchr(): %s\n", str);
//	ft_printf("Before ft_memchr(): %s\n\n", str1);

// // 	ret = memchr(str, 'i', 15*sizeof(char));
// 	ret1 = ft_memchr(str1, 'i', 15*sizeof(char));

//	ft_printf("After    memchr():  %s\n", ret);
//	ft_printf("After ft_memchr():  %s\n", ret1);

// 	return 0;
// }

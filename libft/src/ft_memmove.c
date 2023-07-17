/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:53:39 by ael-malt          #+#    #+#             */
/*   Updated: 2023/07/13 19:02:49 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	if (!dest || !src)
		return (NULL);
	d = dest;
	s = src;
	if (d > s)
	{
		i = n;
		while ((int)--i >= 0)
			d[i] = s[i];
	}
	else
	{
		i = -1;
		while (++i < n)
			d[i] = s[i];
	}
	return (d);
}

// int	main()
// {
// 	char src[26] = "abcdefghijklmnopqrstuvwxyz";
// 	char dst[50] = "GeeksForGeeks is for programming geeks.";
// 	char src1[26] = "abcdefghijklmnopqrstuvwxyz";
// 	char dst1[50] = "GeeksForGeeks is for programming geeks.";
//	ft_printf("Before ft_memmove(): %s\n", dst);
//	ft_printf("Before    memmove(): %s\n\n", dst1);

// 	memmove(dst, src, 27*sizeof(char));
// 	ft_memmove(dst1, src1, 27*sizeof(char));

//	ft_printf("After ft_memmove():  %s\n", dst);
//	ft_printf("After    memmove():  %s\n", dst1);

// 	return 0;
// }

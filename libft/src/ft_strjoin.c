/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:04:40 by ael-malt          #+#    #+#             */
/*   Updated: 2023/07/13 19:02:49 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_s;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_s = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!new_s)
		return (new_s);
	ft_strlcpy(new_s, s1, s1_len + 1);
	ft_strlcat(&new_s[s1_len], s2, s2_len + 1);
	return (new_s);
}

// int main(int argc, char const *argv[])
// {
// 	(void) argc;

//	ft_printf("%s", ft_strjoin(argv[1], argv[2]));
// }

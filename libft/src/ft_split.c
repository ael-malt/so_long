/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-malt <ael-malt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:21:45 by ael-malt          #+#    #+#             */
/*   Updated: 2023/05/11 16:09:38 by ael-malt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	**ft_malloc_error(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

size_t	ft_get_nb_strs(char const *s, char c)
{
	size_t	i;
	size_t	nb_strs;

	if (!s[0])
		return (0);
	i = 0;
	nb_strs = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			nb_strs++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		nb_strs++;
	return (nb_strs);
}

void	ft_get_next_str(char **next_str, size_t *next_str_len, char c)
{
	size_t	i;

	*next_str += *next_str_len;
	*next_str_len = 0;
	i = 0;
	while (**next_str && **next_str == c)
		(*next_str)++;
	while ((*next_str)[i])
	{
		if ((*next_str)[i] == c)
			return ;
		(*next_str_len)++;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	char	*next_str;
	size_t	next_str_len;
	size_t	nb_strs;
	size_t	i;

	if (!s)
		return (NULL);
	nb_strs = ft_get_nb_strs(s, c);
	strs = (char **)malloc(sizeof(char *) * (nb_strs + 1));
	if (!strs)
		return (NULL);
	i = -1;
	next_str = (char *)s;
	next_str_len = 0;
	while (++i < nb_strs)
	{
		ft_get_next_str(&next_str, &next_str_len, c);
		strs[i] = (char *)malloc(sizeof(char) * (next_str_len + 1));
		if (!strs)
			return (ft_malloc_error(strs));
		ft_strlcpy(strs[i], next_str, next_str_len + 1);
	}
	strs[i] = NULL;
	return (strs);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:30:30 by ael-malt          #+#    #+#             */
/*   Updated: 2023/07/07 16:36:02 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line_bonus.h"

static void	ft_gnl_strlcpy(char *buf, char *new_s, size_t i)
{
	size_t	j;

	j = 0;
	while (buf[j])
	{
		new_s[i] = buf[j];
		if (new_s[i] == '\n')
		{
			i++;
			new_s[i] = '\0';
			return ;
		}
		i++;
		j++;
	}
	new_s[i] = '\0';
}

static void	*ft_calloc_gnl(size_t nmemb, size_t size)
{
	char	*ret;
	size_t	i;

	i = 0;
	if (!nmemb || !size)
		return (malloc(1));
	if (size * nmemb / nmemb != size)
		return (NULL);
	ret = malloc(nmemb * size);
	if (!ret)
		return (NULL);
	while (i < nmemb)
		ret[i++] = '\0';
	return ((void *)ret);
}

char	*ft_gnl_strjoin(char *ret, char *buf)
{
	char	*new_s;
	size_t	i;
	size_t	j;

	if (!buf)
		return (0);
	i = ft_strlen(ret) + ft_strlen(buf);
	new_s = (char *)ft_calloc_gnl(i + 1, sizeof(char));
	if (!new_s)
		return (0);
	i = 0;
	j = 0;
	if (ret)
		while (ret[j])
			new_s[i++] = ret[j++];
	free(ret);
	ft_gnl_strlcpy(buf, new_s, i);
	return (new_s);
}

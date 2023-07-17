/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-malt <ael-malt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:16:09 by amine             #+#    #+#             */
/*   Updated: 2023/07/17 13:45:40 by ael-malt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strrev(char *str)
{
	int		f;
	int		l;
	char	*new_str;
	int		tmp;

	new_str = str;
	f = 0;
	l = ft_strlen(str) - 1;
	while (f < l)
	{
		tmp = new_str[f];
		new_str[f] = new_str[l];
		new_str[l] = tmp;
		f++;
		l--;
	}
	return (str);
}

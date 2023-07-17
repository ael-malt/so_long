/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmatrix_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:56:24 by amine             #+#    #+#             */
/*   Updated: 2023/07/07 18:56:35 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_putmatrix_fd(char **m, int nl, int fd)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (m && m[i])
	{
		if (nl)
			count += ft_putendl_fd(m[i], fd);
		else
			count += ft_putstr_fd(m[i], fd);
		i++;
	}
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrixtolst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:54:30 by amine             #+#    #+#             */
/*   Updated: 2023/07/07 18:55:23 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_matrixtolst(char **matrix)
{
	t_list	*lst;
	int		i;

	lst = NULL;
	i = -1;
	while (matrix[++i])
		ft_lstadd_back(&lst, ft_lstnew(ft_strdup(matrix[i])));
	return (lst);
}

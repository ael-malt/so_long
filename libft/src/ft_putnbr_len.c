/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-malt <ael-malt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 22:37:12 by ael-malt          #+#    #+#             */
/*   Updated: 2023/05/11 16:09:38 by ael-malt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_putnbr_len(int n, int *len)
{
	if (n == -2147483648)
	{
		ft_putstr_len("-2147483648", len);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		ft_putchar_len('-', len);
	}
	if (n >= 10)
		ft_putnbr_len(n / 10, len);
	ft_putchar_len(n % 10 + '0', len);
}

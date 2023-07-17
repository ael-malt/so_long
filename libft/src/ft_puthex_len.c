/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-malt <ael-malt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 22:57:57 by ael-malt          #+#    #+#             */
/*   Updated: 2023/05/11 16:09:38 by ael-malt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_puthex_len(unsigned long n, int lc_uc, int *len)
{
	if (n >= 16)
	{
		ft_puthex_len(n / 16, lc_uc, len);
		ft_puthex_len(n % 16, lc_uc, len);
	}
	else if (n < 10)
		ft_putchar_len(n + '0', len);
	else
	{
		if (lc_uc == 0)
			ft_putchar_len(n + 'W', len);
		if (lc_uc == 1)
			ft_putchar_len(n + '7', len);
	}
}

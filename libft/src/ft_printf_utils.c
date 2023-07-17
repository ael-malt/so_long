/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-malt <ael-malt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:53:02 by ael-malt          #+#    #+#             */
/*   Updated: 2023/05/11 16:09:38 by ael-malt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_putchar_len(char c, int *len)
{
	*len += write(1, &c, 1);
}

void	ft_putstr_len(char *s, int *len)
{
	int	i;

	if (!s)
		*len += write(1, "(null)", 6);
	else
	{
		i = 0;
		while (s[i])
			*len += write(1, &s[i++], 1);
	}
}

void	ft_putptr_len(void *p, int *len)
{
	if (!p)
		(ft_putstr_len("(nil)", len));
	else
	{
		ft_putstr_len("0x", len);
		ft_puthex_len((unsigned long long)p, 0, len);
	}
}

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

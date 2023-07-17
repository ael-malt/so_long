/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-malt <ael-malt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:48:05 by ael-malt          #+#    #+#             */
/*   Updated: 2023/04/22 16:28:50 by ael-malt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

// Printf
int		ft_printf(const char *text, ...);

// Utils
void	ft_putchar_len(char c, int *len);
void	ft_putstr_len(char *s, int *len);
void	ft_putptr_len(void *p, int *len);
void	ft_putnbr_len(int n, int *len);
void	ft_putunbr_len(unsigned int n, int *len);
void	ft_puthex_len(unsigned long n, int lc_uc, int *len);

#endif

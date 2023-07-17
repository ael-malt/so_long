/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-malt <ael-malt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:34:09 by ael-malt          #+#    #+#             */
/*   Updated: 2022/12/08 13:37:31 by ael-malt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	write_arg(char c, va_list	list, int *len)
{
	if (c == 'c')
		ft_putchar_len(va_arg(list, int), len);
	else if (c == 's')
		ft_putstr_len((char *)va_arg(list, const char *), len);
	else if (c == 'p')
		ft_putptr_len(va_arg(list, void *), len);
	else if (c == 'd')
		ft_putnbr_len(va_arg(list, int), len);
	else if (c == 'i')
		ft_putnbr_len(va_arg(list, int), len);
	else if (c == 'u')
		ft_putunbr_len(va_arg(list, unsigned int), len);
	else if (c == 'x')
		ft_puthex_len(va_arg(list, unsigned int), 0, len);
	else if (c == 'X')
		ft_puthex_len(va_arg(list, unsigned int), 1, len);
	else if (c == '%')
		ft_putchar_len('%', len);
}

int	ft_printf(const char *text, ...)
{
	va_list	list;
	int		i;
	int		len;
	int		text_len;

	text_len = ft_strlen(text);
	va_start(list, text);
	len = 0;
	i = 0;
	while (i < text_len)
	{
		if (text[i] != '%')
		{
			write(1, &text[i], 1);
			len++;
		}
		else
			write_arg(text[i++ + 1], list, &len);
		i++;
	}
	va_end(list);
	return (len);
}

/*
int main()
{
	char			c = 'c';
	char			*s = "Hello World ! ";
	void			*p = 0;
	int				d = 42;
	int				i = 0;
	unsigned int	u = 4294967295;
	int				x = 69;
	int				X = 420;

printf("ft_printf len: %d\n\n", ft_printf("Character: '%c'\nString:
'%s'\nPointer: '%p\nDecimal: '%d'\nInteger: '%i'\nUnsigned Int:
'%u'\nLowercase Hex: '%x'\nUpercaseHex: '%X'\n\n", c, s, p, d, i, u, x, X));
printf("printf len: %d\n\n", printf("Character: '%c'\nString: '%s'\nPointer:
'%p\nDecimal: '%d'\nInteger: '%i'\nUnsigned Int: '%u'\nLowercase Hex:
'%x'\nUpercaseHex: '%X'\n\n", c, s, p, d, i, u, x, X));
}
*/

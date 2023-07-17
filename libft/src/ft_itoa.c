/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:59:34 by ael-malt          #+#    #+#             */
/*   Updated: 2023/07/13 19:02:49 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	get_nlen(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*max_int(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 12);
	if (!str)
		return (0);
	ft_strlcpy(str, "-2147483648", 12);
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		n_len;

	if (n == -2147483648)
		return (max_int());
	n_len = get_nlen(n);
	str = (char *)malloc(sizeof(char) * (n_len + 1));
	if (!str)
		return (0);
	i = n_len;
	if (n < 0)
		n = -n;
	str[0] = 0;
	str[i] = '\0';
	while (--i >= 0)
	{
		if (!(i == 0 && str[0] == '-'))
			str[i] = n % 10 + '0';
		n = n / 10;
	}
	if (str[0] == '0' && n_len > 1)
		str[0] = '-';
	return (str);
}

// int	main(void)
// {
//	ft_printf("ft_itoa: %s\n", ft_itoa(-1));
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:27:19 by ael-malt          #+#    #+#             */
/*   Updated: 2023/07/13 19:04:33 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

static int	check_line(char *buf)
{
	int	i;
	int	is_new_line;
	int	j;

	i = 0;
	j = 0;
	is_new_line = 0;
	while (buf[i])
	{
		if (is_new_line)
			buf[j++] = buf[i];
		if (buf[i] == '\n')
			is_new_line = 1;
		buf[i++] = '\0';
	}
	return (is_new_line);
}

char	*get_next_line(int fd)
{
	static char		buf[BUFFER_SIZE + 1];
	char			*ret;
	int				i;

	i = 0;
	if (BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		while (buf[i])
			buf[i++] = 0;
		return (NULL);
	}
	ret = NULL;
	while (buf[0] || read(fd, buf, BUFFER_SIZE) > 0)
	{
		ret = ft_gnl_strjoin(ret, buf);
		if (check_line(buf))
			break ;
	}
	return (ret);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("test", O_RDONLY | O_CREAT);
// 	line = (get_next_line(fd));	
// 	// ft_printf("%s", line);
// 	while (line != 0)
// 	{
// 		ft_printf("%s", line);
// 		free(line);
// 		line = (get_next_line(fd));
// 	}
// }

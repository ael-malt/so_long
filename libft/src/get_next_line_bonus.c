/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:27:19 by ael-malt          #+#    #+#             */
/*   Updated: 2023/07/13 19:04:08 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line_bonus.h"

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
	static char		buf[FOPEN_MAX][BUFFER_SIZE + 1];
	char			*ret;
	int				i;

	i = 0;
	if (BUFFER_SIZE < 1 || read(fd, 0, 0) < 0 || fd >= FOPEN_MAX)
	{
		while (fd >= 0 && fd <= FOPEN_MAX && buf[fd][i])
			buf[fd][i++] = 0;
		return (NULL);
	}
	ret = NULL;
	while (buf[fd][0] || read(fd, buf[fd], BUFFER_SIZE) > 0)
	{
		ret = ft_gnl_strjoin(ret, buf[fd]);
		if (check_line(buf[fd]))
			break ;
	}
	return (ret);
}

//int	main(void)
//{
//	int		test0;
//	int		test1;
//	int		test2;
//	char	*line;

//	test0 = open("test", O_RDONLY | O_CREAT);
//	test1 = open("test1", O_RDONLY | O_CREAT);
//	test2 = open("test2", O_RDONLY | O_CREAT);

//	line = "";
//	while (line != 0)
//	{
//		line = (get_next_line(test0));
//		ft_printf("%s", line);
//		line = (get_next_line(test1));
//		ft_printf("%s", line);
//		line = (get_next_line(test2));
//		ft_printf("%s", line);
//		free(line);
//	}
//}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-malt <ael-malt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:07:23 by ael-malt          #+#    #+#             */
/*   Updated: 2023/07/17 13:44:19 by ael-malt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <unistd.h>
# include <bsd/string.h>
# include <string.h>
# include <strings.h>
# include <ctype.h>
# include <stdlib.h>
# include <stdint.h>

# include "ft_printf.h"
# include "get_next_line.h"
# include "get_next_line_bonus.h"

// Mandatory Part 1
int			ft_atoi(const char	*nptr);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *s, int c, size_t n);
char		*ft_strchr(const char	*s, int c);
char		*ft_strdup(const char *s);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strrchr(const char *s, int c);
int			ft_tolower(int c);
int			ft_toupper(int c);

// Mandatory Part 2
char		*ft_itoa(int n);
int			ft_putchar_fd(char c, int fd);
int			ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
int			ft_putstr_fd(char *s, int fd);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_strjoin(char const *s1, char const *s2);
char		**ft_split(char const *s, char c);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);

// Bonus Part
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstnew(void *content);
int			ft_lstsize(t_list *lst);

// Math
int			ft_sqrt(int nb);
int			ft_recursive_power(int nb, int power);

// My structs

// Vector with x and y coordinates
typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

// My functions
void		ft_swap(int *a, int *b);
char		*ft_strrev(char *str);
int			ft_countchar(char *s, char c);
char		*ft_strenlarge(char *s1, char *s2);
char		**ft_dup_matrix(char **m);
char		**ft_extend_matrix(char **in, char *newstr);
void		ft_free_matrix(char ***m);
char		**ft_lsttomatrix(t_list *lst);
int			ft_matrixlen(char **m);
t_list		*ft_matrixtolst(char **matrix);
int			ft_putmatrix_fd(char **m, int nl, int fd);
t_vector	ft_newvector(int x, int y);
int			ft_strrncmp(const char *s1, const char *s2, size_t n);

#endif

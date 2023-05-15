/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:21:38 by dylan             #+#    #+#             */
/*   Updated: 2023/04/29 20:01:01 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stddef.h>
# include <sys/types.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdint.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
size_t	ft_strlen(char const *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_lstsize(t_list *lst);
int		ft_atoi(const char *str);
int		ft_isalnum(int c);
int		ft_printf(const char *str, ...);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strdup(char *s);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char *s, char c);
char	*ft_itoa(int n);
char	*get_next_line(int fd);
char	*makeline(char *stash);
char	*getstash(int fd, char *stash, ssize_t *len, int *eof);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *memoryBlock, int to_find, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_bzero(void *s, size_t n);
void	ft_pfputchar(char c, int *count);
void	processtype(char c, va_list ag_list, int *count);
void	ft_pfputstr(const char *src, int *count);
void	ft_pfputnbr(int nb, int *count);
void	ft_putnbru(unsigned int nb, int *count);
void	ft_hex(unsigned int nb, int *count, char c);
void	ft_putptr(uintptr_t nb, int *count, int io);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

#endif
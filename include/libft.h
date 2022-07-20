/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:26:40 by fkernbac          #+#    #+#             */
/*   Updated: 2022/03/30 17:55:05 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd, int BUFFER_SIZE);
size_t	newline_index(char *string);
void	*free_and_null(void *pointer);
int		ft_printf(const char *str, ...);
char	*ft_hextoa(unsigned int n, char x);
char	*ft_ptoa(unsigned long n);
char	*ft_utoa(unsigned int n);
long	ft_atoi(const char *string);
void	ft_bzero(void *pointer, size_t size);
void	*ft_calloc(size_t number, size_t size);
int		ft_isalnum(int character);
int		ft_isalpha(int character);
int		ft_isascii(int character);
int		ft_isdigit(int character);
int		ft_isprint(int character);
char	*ft_itoa(int n);
void	*ft_memchr(const void *memory, int target, size_t size);
int		ft_memcmp(const void *mem_a, const void *mem_b, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t size);
void	*ft_memmove(void *dest, const void *src, size_t size);
void	*ft_memset(void *pointer, int content, size_t size);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *string, char c);
char	*ft_strchr(const char *string, int character);
char	*ft_strdup(const char *string);
void	ft_striteri(char *string, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *first, char const *last);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *string);
char	*ft_strmapi(char const *string, char (*f)(unsigned int, char));
int		ft_strncmp(const char *a, const char *b, size_t size);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *string, int character);
char	*ft_strtrim(char const *string, char const *set);
char	*ft_substr(char const *string, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif

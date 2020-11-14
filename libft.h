/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 13:07:38 by ezachari          #+#    #+#             */
/*   Updated: 2020/11/13 21:32:05 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	void				*content;
	struct s_list		*next;
}					t_list;
t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *str);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strndup(const char *s1, int size);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strdup(const char *str);
char				*ft_strchr(const char *str, int ch);
char				*ft_strrchr(const char *str, int ch);
char				*ft_strnstr(const char *big, const char *little,
					size_t len);
char				*ft_itoa(int n);
char				*ft_strncpy(char *dest, char *src, unsigned int n);
char				*ft_uitoa(unsigned int n);
char				*ft_itoa_base(unsigned int n, const char *base);
char				**ft_split(char const *s, char c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s1, char const *set);
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				*ft_memset(void *dest, const int value, size_t size);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, void *src, int ch, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *src, int c, size_t n);
void				*ft_calloc(size_t num, size_t size);
void				ft_putendl_fd(char *s, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar_fd(char c, int fd);
int					ft_memcmp(const void *buf1, const void *buf2, size_t n);
int					ft_isdigit(int ch);
int					ft_isalpha(int ch);
int					ft_isascii(int ch);
int					ft_isprint(int ch);
int					ft_isalnum(int ch);
int					ft_tolower(int ch);
int					ft_toupper(int ch);
int					ft_atoi(const char *str);
int					ft_strncmp(const char *string1, const char *string2,
					size_t num);
int					ft_lstsize(t_list *lst);
int					ft_set(char c, char *set);
int					ft_putchar(char c);
int					ft_putstr(char *s);
int					ft_putcharn(char c, int n);
int					ft_putstrn(char *s, int n);
char				*ft_strcpy(char *dest, char *src);
#endif

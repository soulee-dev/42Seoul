/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:42:36 by soulee            #+#    #+#             */
/*   Updated: 2022/11/08 20:40:07 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_strlen(char *s);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, void *src, size_t n);
void			*ft_memmove(void *dst, void *src, size_t len);
size_t			ft_strlcpy(char *dst, char *src, size_t size);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(char *s, int c);
char			*ft_strrchr(char *s, int c);
int				ft_strncmp(char *s1, char *s2, size_t n);
char			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(void *s1, void *s2, size_t n);
char			*ft_strstr(char *str, char *to_find);
int				ft_atoi(char *str);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(char *src);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
// char 			*ft_strtrim(char const *s1, char const *set);
#endif
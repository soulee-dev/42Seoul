/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 03:22:38 by soulee            #+#    #+#             */
/*   Updated: 2022/11/19 18:05:18 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stddef.h>
// REMOVE BEFORE FLIGHT
# include <stdio.h>
# include <fcntl.h>
// REMOVE BEFORE FLIGHT
size_t	ft_strlen(const char *str);
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(char *s, int c);
char	*ft_strndup(const char *s1, size_t n);
char	*ft_extract_line(char *s);
char	*ft_remove_line(char *s);
#endif
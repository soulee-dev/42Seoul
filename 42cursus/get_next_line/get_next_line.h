/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 03:22:38 by soulee            #+#    #+#             */
/*   Updated: 2022/12/11 16:13:48 by soulee           ###   ########.fr       */
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
char	*ft_remain_text(char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_extract_line(char *s);
char	*get_next_line(int fd);
#endif
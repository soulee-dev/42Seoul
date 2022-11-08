// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   ft_strtrim.c                                       :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/11/08 15:16:17 by soulee            #+#    #+#             */
// /*   Updated: 2022/11/08 15:40:30 by soulee           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "libft.h"

// char	*reverse_string(char const s)
// {
// 	int		i;
// 	int		len;
// 	char	*result_str;

// 	i = 0;
// 	len = ft_strlen(s);
// 	result_str = malloc(sizeof(char) * (len + 1));
// 	while (i < len)
// 	{
// 		result_str[i] = s[len - i];
// 		i++;
// 	}
// 	return (result_str);
// }

// char *ft_strtrim(char const *s1, char const *set)
// {
// 	char	*result_str;

// 	result_str = malloc(sizeof(char) * (ft_strlen(set) * 2 + 1));
// 	result_str = reverse_string(ft_strstr
// 			(reverse_string(ft_strstr(s1, set)), set));

// 	return (result_str);
// }

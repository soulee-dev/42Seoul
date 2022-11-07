/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:44:31 by soulee            #+#    #+#             */
/*   Updated: 2022/11/07 18:47:20 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, void *src, size_t len)
{
	unsigned char	*pdst;
	unsigned char	*psrc;

	pdst = dst;
	psrc = src;
	while (len--)
		*pdst++ = *psrc++;
	return (dst);
}

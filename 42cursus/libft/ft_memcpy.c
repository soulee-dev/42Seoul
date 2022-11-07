/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:39:02 by soulee            #+#    #+#             */
/*   Updated: 2022/11/07 18:46:57 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	unsigned char	*pdst;
	unsigned char	*psrc;

	pdst = dst;
	psrc = src;
	while (n--)
		*pdst++ = *psrc++;
	return (dst);
}

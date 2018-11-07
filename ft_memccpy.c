/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:47:06 by dde-jesu          #+#    #+#             */
/*   Updated: 2018/11/07 10:33:58 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const unsigned char	*c_src = src;
	unsigned char		*c_dst;

	c_dst = dst;
	while (n--)
		if (c_src[n] == c)
			return (dst + n + 1);
		else
			c_dst[n] = c_src[n];
	return (0);
}

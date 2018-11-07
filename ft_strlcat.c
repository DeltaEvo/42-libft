/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:18:20 by dde-jesu          #+#    #+#             */
/*   Updated: 2018/11/07 10:19:18 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	const size_t	osize = size;

	while (*dst && size--)
		dst++;
	while (*src && --size)
		*dst++ = *src++;
	*dst = 0;
	return (osize + ft_strlen(src) - 1);
}

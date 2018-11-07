/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:16:44 by dde-jesu          #+#    #+#             */
/*   Updated: 2018/11/07 15:21:30 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	const char	*odst = dst;

	while (*dst)
		dst++;
	while (*src && n--)
		*dst++ = *src++;
	*dst = 0;
	return ((char *)odst);
}

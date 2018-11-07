/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:15:18 by dde-jesu          #+#    #+#             */
/*   Updated: 2018/11/07 10:15:39 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	const char	*odst = dst;

	while (n--)
		*dst++ = *src ? *src++ : 0;
	*dst = '\0';
	return ((char *)odst);
}

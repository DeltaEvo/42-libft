/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:16:44 by dde-jesu          #+#    #+#             */
/*   Updated: 2018/11/07 10:16:49 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	const char	*odst = dst;

	while (*dst)
		dst++;
	ft_strncpy(dst, src, n);
	return ((char *)odst);
}

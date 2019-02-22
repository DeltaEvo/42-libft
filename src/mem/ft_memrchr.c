/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:09:55 by dde-jesu          #+#    #+#             */
/*   Updated: 2019/02/22 17:10:23 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memrchr(const void *s, int c, size_t n)
{
	const unsigned char	*b_s = s + n;

	while (n--)
		if (*--b_s == (unsigned char)c)
			return ((void *)b_s);
	return (NULL);
}

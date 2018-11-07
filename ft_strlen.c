/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:15:52 by dde-jesu          #+#    #+#             */
/*   Updated: 2018/11/07 10:38:26 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>

size_t	ft_strlen(const char *s)
{
	size_t		len;
	uint32_t	part;

	len = 0;
	while (1)
	{
		part = *(uint32_t *)s;
		if ((part & 0xff) == 0)
			return (len);
		if ((part & 0xff00) == 0)
			return (len + 1);
		if ((part & 0xff0000) == 0)
			return (len + 2);
		if ((part & 0xff000000) == 0)
			return (len + 3);
		len += sizeof(uint32_t);
		s += sizeof(uint32_t);
	}
}

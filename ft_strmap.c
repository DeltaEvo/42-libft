/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:31:18 by dde-jesu          #+#    #+#             */
/*   Updated: 2018/11/07 11:42:06 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	const char	*new = malloc(ft_strlen(s));
	char		*tmp;

	if (!(tmp = (char *)new))
		return (NULL);
	while (*s)
		*tmp++ = f(*s++);
	return ((char *)new);
}

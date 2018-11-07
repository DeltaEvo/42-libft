/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:58:51 by dde-jesu          #+#    #+#             */
/*   Updated: 2018/11/07 12:05:36 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	const size_t	s1_len = ft_strlen(s1);
	const size_t	s2_len = ft_strlen(s2);
	const char		*str = malloc(s1_len + s2_len + 1);

	if (!str)
		return (NULL);
	ft_memcpy((void *)str, s1, s1_len);
	ft_memcpy((void *)str + s1_len, s2, s2_len);
	((char *)str)[s1_len + s2_len] = 0;
	return ((char *)str);
}

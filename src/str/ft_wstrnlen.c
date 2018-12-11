/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wctomb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 13:44:03 by dde-jesu          #+#    #+#             */
/*   Updated: 2018/12/11 14:09:13 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <stdint.h>

size_t	ft_wcstrnlen(const wchar_t *s, size_t max)
{
	uint8_t	curr;
	size_t	len;

	len = 0;
	while (*s && len < max)
	{
		if ((unsigned)*s < 0x80)
			curr = 1;
		else if ((unsigned)*s < 0x800)
			curr = 2;
		else if ((unsigned)*s < 0xd800 || (unsigned)*s - 0xe000 < 0x2000)
			curr = 3;
		else if ((unsigned)*s - 0x10000 < 0x100000)
			curr = 4;
		else
			break ;
		if (len + curr <= max)
			len += curr;
		else
			break ;
		s++;
	}
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wctomb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 13:44:03 by dde-jesu          #+#    #+#             */
/*   Updated: 2018/12/11 14:10:04 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>

size_t	ft_wctomb(char *s, wchar_t wc)
{
	if ((unsigned)wc < 0x80)
		return ((*s = wc) || 1);
	else if ((unsigned)wc < 0x800)
	{
		*s++ = 0xc0 | (wc >> 6);
		*s = 0x80 | (wc & 0x3f);
		return (2);
	}
	else if ((unsigned)wc < 0xd800 || (unsigned)wc - 0xe000 < 0x2000)
	{
		*s++ = 0xe0 | (wc >> 12);
		*s++ = 0x80 | ((wc >> 6) & 0x3f);
		*s = 0x80 | (wc & 0x3f);
		return (3);
	}
	else if ((unsigned)wc - 0x10000 < 0x100000)
	{
		*s++ = 0xf0 | (wc >> 18);
		*s++ = 0x80 | ((wc >> 12) & 0x3f);
		*s++ = 0x80 | ((wc >> 6) & 0x3f);
		*s = 0x80 | (wc & 0x3f);
		return (4);
	}
	return (-1);
}

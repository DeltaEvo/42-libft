/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 10:12:17 by dde-jesu          #+#    #+#             */
/*   Updated: 2018/12/05 14:12:44 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/convert.h"

static void	ft_uint_to_str_p(uintmax_t nb, char *str, uint8_t *len, int8_t b)
{
	const char	*base = b > 0 ? "0123456789abcdef" : "0123456789ABCDEF";
	uintmax_t	tmp;
	uint8_t		i;

	if (b < 0)
		b = -b;
	tmp = nb;
	*len = 1;
	while (tmp /= b)
		(*len)++;
	i = *len;
	str[i] = 0;
	while (i--)
	{
		str[i] = base[nb % b];
		nb /= b;
	}
}

t_int_str	ft_uint_to_str(uintmax_t nb)
{
	t_int_str	res;

	ft_uint_to_str_p(nb, res.str, &res.len, 10);
	return (res);
}

t_int_str	ft_int_to_str(intmax_t nb)
{
	t_int_str		res;

	ft_uint_to_str_p((uintmax_t)(nb < 0 ? -nb : nb), res.str + (nb < 0),
			&res.len, 10);
	if (nb < 0)
	{
		*res.str = '-';
		res.len++;
	}
	return (res);
}

t_int_str16	ft_uint_to_str16(uintmax_t nb, uint8_t maj)
{
	t_int_str16	res;

	ft_uint_to_str_p(nb, res.str, &res.len, maj ? -16 : 16);
	return (res);
}

t_int_str16	ft_int_to_str16(intmax_t nb, uint8_t maj)
{
	t_int_str16		res;

	ft_uint_to_str_p((uintmax_t)(nb < 0 ? -nb : nb), res.str + (nb < 0),
			&res.len, maj ? -16 : 16);
	if (nb < 0)
	{
		*res.str = '-';
		res.len++;
	}
	return (res);
}

t_int_str8	ft_uint_to_str8(uintmax_t nb)
{
	t_int_str8	res;

	ft_uint_to_str_p(nb, res.str, &res.len, 8);
	return (res);
}

t_int_str8	ft_int_to_str8(intmax_t nb)
{
	t_int_str8		res;

	ft_uint_to_str_p((uintmax_t)(nb < 0 ? -nb : nb), res.str + (nb < 0),
			&res.len, 8);
	if (nb < 0)
	{
		*res.str = '-';
		res.len++;
	}
	return (res);
}

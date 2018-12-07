/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:08:58 by dde-jesu          #+#    #+#             */
/*   Updated: 2018/12/07 16:09:27 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/io.h"

int	ft_atoi_rd(t_readable *rd)
{
	int		result;
	char	mod;
	char	c;

	while ((c = io_peek(rd)) && (c == ' ' || (c >= '\t' && c <= '\r')))
		rd->index++;
	result = 0;
	mod = 0;
	if (c == '-' || c == '+')
	{
		mod = c == '-';
		rd->index++;
	}
	while ((c = io_peek(rd)) && (c >= '0' && c <= '9'))
	{
		result = result * 10 + c - '0';
		rd->index++;
	}
	return (mod ? -result : result);
}

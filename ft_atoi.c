/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 09:40:16 by dde-jesu          #+#    #+#             */
/*   Updated: 2018/11/08 11:31:50 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

int	ft_atoi(const char *str)
{
	int		result;
	char	mod;

	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	result = 0;
	mod = *str == '-' || *str == '+' ? *str++ == '-' : 0;
	while (*str >= '0' && *str <= '9')
		if (result > INT_MAX / 10)
			return (mod ? 0 : -1);
		else
			result = result * 10 + *str++ - '0';
	return (mod ? -result : result);
}

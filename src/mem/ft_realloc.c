/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:09:44 by dde-jesu          #+#    #+#             */
/*   Updated: 2018/12/07 16:10:10 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/mem.h"
#include <stdlib.h>

void	*ft_realloc(void *o_ptr, size_t oldsize, size_t newsize)
{
	void	*ptr;

	ptr = malloc(newsize);
	if (oldsize)
	{
		ft_memcpy(ptr, o_ptr, oldsize);
		free(o_ptr);
	}
	return (ptr);
}

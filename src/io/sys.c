/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 12:38:39 by dde-jesu          #+#    #+#             */
/*   Updated: 2018/12/17 12:23:57 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/io.h"

ssize_t	flush_fd(t_writable *w)
{
	ssize_t	ret;
	size_t	index;

	index = w->index;
	w->index = 0;
	if ((ret = write((int)w->data, w->buffer, index)) < 0)
		return (ret);
	return (ret);
}

ssize_t	fill_fd(t_readable *r)
{
	ssize_t	ret;

	r->index = 0;
	if ((ret = read((int)r->data, r->buffer, r->buffer_size)) < 0)
		return (ret);
	return (r->len = ret);
}

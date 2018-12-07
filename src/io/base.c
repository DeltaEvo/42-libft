/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 13:02:00 by dde-jesu          #+#    #+#             */
/*   Updated: 2018/12/06 11:57:05 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/io.h"
#include "ft/mem.h"

t_readable	init_readable(t_io_fill fill, void *data)
{
	return ((t_readable) {
		.index = 0,
		.len = 0,
		.fill = fill,
		.data = data
	});
}

t_writable	init_writable(t_io_flush flush, void *data)
{
	return ((t_writable) {
		.index = 0,
		.flush = flush,
		.data = data
	});
}

ssize_t		io_write(t_writable *w, char data[], size_t len)
{
	const size_t	remaining = BUFFER_SIZE - w->index;

	if (remaining < len)
	{
		ft_memcpy(w->buffer + w->index, data, remaining);
		if (!w->flush(w))
			return (-1);
		data += remaining;
		len -= remaining;
	}
	ft_memcpy(w->buffer + w->index, data, len);
	w->index += len;
	return (1);
}

ssize_t		io_read(t_readable *r, char data[], size_t len)
{
	const size_t	remaining = r->len - r->index;
	size_t			copied;

	if (remaining < len)
	{
		copied = remaining;
		ft_memcpy(data, r->buffer + r->index, remaining);
		r->fill(r);
		data += remaining;
		len -= remaining;
	}
	else
		copied = 0;
	ft_memcpy(data, r->buffer + r->index, len);
	r->index += len;
	return (len + copied);
}

char		io_peek(t_readable *r)
{
	if (r->index == r->len)
		r->fill(r);
	return (r->buffer[r->index]);
}

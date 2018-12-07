/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 12:38:39 by dde-jesu          #+#    #+#             */
/*   Updated: 2018/12/06 12:03:23 by dde-jesu         ###   ########.fr       */
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
	if ((ret = read((int)r->data, r->buffer, BUFFER_SIZE)) < 0)
		return (ret);
	return (r->len = ret);
}

static t_readable g_stdin_r = {
	.index = 0,
	.len = 0,
	.fill = fill_fd,
	.data = (void *)STDIN_FILENO
};
t_readable *g_stdin = &g_stdin_r;

static t_writable g_stdout_r = {
	.index = 0,
	.flush = flush_fd,
	.data = (void *)STDOUT_FILENO
};
t_writable *g_stdout = &g_stdout_r;

static t_writable g_stderr_r = {
	.index = 0,
	.flush = flush_fd,
	.data = (void *)STDERR_FILENO
};
t_writable *g_stderr = &g_stderr_r;

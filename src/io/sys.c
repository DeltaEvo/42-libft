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

ssize_t	flush_fd(int fd, t_writable *w)
{
	ssize_t	ret;
	size_t	index;

	index = w->index;
	w->index = 0;
	if ((ret = write(fd, w->buffer, index)) < 0)
		return (ret);
	return (ret);
}

ssize_t	fill_fd(int fd, t_readable *r)
{
	ssize_t	ret;

	r->index = 0;
	if ((ret = read(fd, r->buffer, BUFFER_SIZE)) < 0)
		return (ret);
	return (r->len = ret);
}

ssize_t	fill_stdin(t_readable *r)
{
	return (fill_fd(STDIN_FILENO, r));
}

static t_readable g_stdin_r = {
	.index = 0,
	.len = 0,
	.fill = fill_stdin
};
t_readable *g_stdin = &g_stdin_r;

ssize_t	flush_stdout(t_writable *w)
{
	return (flush_fd(STDOUT_FILENO, w));
}

static t_writable g_stdout_r = {
	.index = 0,
	.flush = flush_stdout
};
t_writable *g_stdout = &g_stdout_r;

ssize_t	flush_stderr(t_writable *w)
{
	return (flush_fd(STDERR_FILENO, w));
}

static t_writable g_stderr_r = {
	.index = 0,
	.flush = flush_stderr
};
t_writable *g_stderr = &g_stderr_r;

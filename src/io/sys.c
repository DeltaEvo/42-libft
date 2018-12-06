/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 12:38:39 by dde-jesu          #+#    #+#             */
/*   Updated: 2018/12/05 14:13:17 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/io.h"

ssize_t	flush_fd(int fd, t_writable *w)
{
	ssize_t	ret;

	w->index = 0;
	if ((ret = write(fd, w->buffer, BUFFER_SIZE)) < 0)
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

t_readable g_stdin = {
	.index = 0,
	.len = 0,
	.fill = fill_stdin
};

ssize_t	flush_stdout(t_writable *w)
{
	return (flush_fd(STDOUT_FILENO, w));
}

t_writable g_stdout = {
	.index = 0,
	.flush = flush_stdout
};

ssize_t	flush_stderr(t_writable *w)
{
	return (flush_fd(STDERR_FILENO, w));
}

t_writable g_stderr = {
	.index = 0,
	.flush = flush_stderr
};

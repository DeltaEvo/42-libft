/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 12:11:03 by dde-jesu          #+#    #+#             */
/*   Updated: 2018/12/06 12:03:35 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_H
# define IO_H

# include <stdint.h>
# include <unistd.h>

# define BUFFER_SIZE (4096)

typedef	struct	s_readable {
	uint8_t	buffer[BUFFER_SIZE];
	size_t	index;
	size_t	len;
	ssize_t	(*fill)(struct s_readable *);
	void	*data;
}				t_readable;

typedef	struct	s_writable {
	uint8_t	buffer[BUFFER_SIZE];
	size_t	index;
	ssize_t	(*flush)(struct s_writable *);
	void	*data;
}				t_writable;

typedef ssize_t	(*t_io_fill)(t_readable *r);
typedef ssize_t	(*t_io_flush)(t_writable *r);

t_readable		init_readable(t_io_fill fill);
t_writable		init_writable(t_io_flush flush);
ssize_t			ft_io_write(t_writable *w, char data[], size_t len);
ssize_t			ft_io_read(t_readable *r, char data[], size_t len);

extern t_readable *g_stdin;
extern t_writable *g_stdout;
extern t_writable *g_stderr;

#endif

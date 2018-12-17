/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 12:11:03 by dde-jesu          #+#    #+#             */
/*   Updated: 2018/12/17 12:25:35 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_H
# define IO_H

# include <stdint.h>
# include <unistd.h>
# include <stdarg.h>

typedef	struct	s_readable {
	uint8_t	*buffer;
	size_t	buffer_size;
	size_t	index;
	size_t	len;
	ssize_t	(*fill)(struct s_readable *);
	void	*data;
}				t_readable;

typedef	struct	s_writable {
	uint8_t	*buffer;
	size_t	buffer_size;
	size_t	index;
	ssize_t	(*flush)(struct s_writable *);
	void	*data;
}				t_writable;

typedef ssize_t	(*t_io_fill)(t_readable *r);
typedef ssize_t	(*t_io_flush)(t_writable *r);

t_readable		init_readable(t_io_fill fill, void *data, uint8_t *buff, size_t s);
t_writable		init_writable(t_io_flush flush, void *data);
ssize_t			io_write(t_writable *w, char data[], size_t len);
ssize_t			io_read(t_readable *r, char data[], size_t len);
char			io_peek(t_readable *r);
ssize_t			fill_fd(t_readable *r);
ssize_t			flush_fd(t_writable *w);

void			ft_putf(char *fmt, ...);
void			ft_putf_fd(int fd, char *fmt, ...);
void			ft_putf_va(int fd, char *fmt, va_list args);
void			ft_putnbr_fd(int n, int fd);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);

#endif

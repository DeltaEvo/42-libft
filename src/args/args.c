/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:07:27 by dde-jesu          #+#    #+#             */
/*   Updated: 2019/01/25 09:15:09 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/args.h"
#include "ft/str.h"
#include "ft/io.h"
#include <stdbool.h>

#define UNKNOWN_OPTION (-1)
#define NO_ARG (-2)

static int	show_err(int err, char *name, char *option, size_t len)
{
	t_writable	stderr;
	uint8_t		buffer[128];

	stderr = init_writable(flush_fd, (void *)1, buffer, sizeof(buffer));
	if (!err)
		return (0);
	if (err == UNKNOWN_OPTION)
	{
		io_write(&stderr, name, ft_strlen(name));
		io_write(&stderr, ": illegal option -- ", 20);
		io_write(&stderr, option, len);
		io_write(&stderr, "\n", 1);
	}
	else if (err == NO_ARG)
	{
		io_write(&stderr, name, ft_strlen(name));
		io_write(&stderr, ": argument required -- ", 23);
		io_write(&stderr, option, len);
		io_write(&stderr, "\n", 1);
	}
	stderr.flush(&stderr);
	return (1);
}

static int	get_value(char **c_arg, const t_arg opt[], char *argv[], int i[2])
{
	char	*arg;
	char	*value;

	arg = *c_arg + i[1];
	if (opt->type == ARG_BOOLEAN)
		*(bool *)opt->value = true;
	else if (opt->type == ARG_STRING || opt->type == ARG_INTEGER)
	{
		value = NULL;
		if (*arg == '=')
		{
			value = arg + 1;
			*c_arg += i[1] + ft_strlen(arg) - 1;
		}
		else if (!*arg)
			value = argv[++i[0]];
		if (!value)
			return (NO_ARG);
		if (opt->type == ARG_STRING)
			*(char **)opt->value = value;
		else if (opt->type == ARG_INTEGER)
			*(int *)opt->value = 0;
	}
	return (0);
}

static int	parse_short(char **c_arg, const t_arg opt[], char *argv[], int *i)
{
	int	indexes[2];
	int	err;

	while (opt->type != ARG_END)
	{
		if (opt->short_name == **c_arg)
		{
			indexes[0] = *i;
			indexes[1] = 1;
			err = get_value(c_arg, opt, argv, indexes);
			*i = *indexes;
			return (show_err(err, argv[0], *c_arg - 1, 1));
		}
		opt++;
	}
	return (show_err(UNKNOWN_OPTION, argv[0], *c_arg, 1));
}

static int	parse_long(char **c_arg, const t_arg opt[], char *argv[], int *i)
{
	size_t	len;
	char	*res;
	int		indexes[2];
	int		err;

	if ((res = ft_strchr(*c_arg, '=')))
	{
		len = res - *c_arg;
	}
	else
		len = ft_strlen(*c_arg);
	while (opt->type != ARG_END)
	{
		if (ft_strncmp(opt->long_name, *c_arg, len) == 0)
		{
			indexes[0] = *i;
			indexes[1] = len;
			err = get_value(c_arg, opt, argv, indexes);
			*i = *indexes;
			return (show_err(err, argv[0], *c_arg - len, len));
		}
		opt++;
	}
	return (show_err(UNKNOWN_OPTION, argv[0], *c_arg, ft_strlen(*c_arg)));
}

int			parse_args(const t_arg args[], int argc, char *argv[])
{
	int		i;
	int		err;
	char	*arg;
	char	*s_arg;

	i = 0;
	err = 0;
	while (++i < argc)
	{
		arg = argv[i];
		s_arg = arg;
		if (arg[0] != '-' || !arg[1])
			return (err ? -1 : i);
		if (arg[1] != '-')
			while (*++s_arg)
				err |= parse_short(&s_arg, args, argv, &i);
		else
		{
			if (!arg[2])
				return (err ? -1 : i + 1);
			s_arg += 2;
			err |= parse_long(&s_arg, args, argv, &i);
		}
	}
	return (err ? -1 : i);
}

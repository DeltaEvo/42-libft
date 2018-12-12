/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 15:08:41 by dde-jesu          #+#    #+#             */
/*   Updated: 2018/12/12 15:34:40 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/args.h"
#include "ft/str.h"
#include "ft/io.h"

int			args_usage(const t_arg args[], char *name, char *usage, char *desc)
{
	ft_putf_fd(1, "Usage: %s [OPTION]... %s\n%s\n\nOptions:\n", name, usage,
			desc);
	while (args->type != ARG_END)
	{
		if (args->short_name && args->long_name)
			ft_putf_fd(1, "  -%c, --%s\n", args->short_name,
					args->long_name);
		else if (args->short_name)
			ft_putf_fd(1, "  -%c\n", args->short_name);
		else if (args->long_name)
			ft_putf_fd(1, "     --%s\n", args->long_name);
		args++;
	}
	return (0);
}

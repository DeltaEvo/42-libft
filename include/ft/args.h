/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 09:55:57 by dde-jesu          #+#    #+#             */
/*   Updated: 2018/12/12 15:37:28 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_H
# define ARGS_H

enum			e_arg_type {
	ARG_END = 0,
	ARG_BOOLEAN,
	ARG_STRING,
	ARG_INTEGER
};

typedef struct	s_arg {
	enum e_arg_type	type;
	const char		short_name;
	const char		*long_name;
	void			*value;
	const char		*help;
}				t_arg;

int				parse_args(const t_arg args[], int argc, char *argv[]);
int				args_usage(const t_arg args[], char *name, char *usage,
							char *desc);
#endif

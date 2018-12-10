/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_parts.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 12:14:53 by dde-jesu          #+#    #+#             */
/*   Updated: 2018/12/10 15:19:08 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_DOUBLE_PARTS_H
# define LIBFT_DOUBLE_PARTS_H

typedef union	u_dparts {
	struct		s_parts {
		uint64_t	frac : 52;
		uint16_t	exp : 11;
		uint8_t		sign : 1;
	}		p;
	double	d;
}				t_dparts;

#endif

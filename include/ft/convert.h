/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 11:54:58 by dde-jesu          #+#    #+#             */
/*   Updated: 2018/12/04 11:41:30 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_H
# define CONVERT_H

# include <stdint.h>
# define LOG2 (0.30102999566)
# define LOG2_8 (0.33333333333)

typedef struct	s_int_str {
	char	str[(uint8_t)(sizeof(uintmax_t) * 8 * LOG2) + 2];
	uint8_t	len;
}				t_int_str;

typedef struct	s_int_str16 {
	char	str[sizeof(uintmax_t) * 2 + 2];
	uint8_t	len;
}				t_int_str16;

typedef struct	s_int_str8 {
	char	str[(uint8_t)(sizeof(uintmax_t) * 8 * LOG2_8) + 2];
	uint8_t	len;
}				t_int_str8;

t_int_str		ft_int_to_str(intmax_t nb);
t_int_str		ft_uint_to_str(uintmax_t nb);
t_int_str16		ft_int_to_str16(intmax_t nbm, uint8_t maj);
t_int_str16		ft_uint_to_str16(uintmax_t nb, uint8_t maj);
t_int_str8		ft_int_to_str8(intmax_t nb);
t_int_str8		ft_uint_to_str8(uintmax_t nb);
#endif

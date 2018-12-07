/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:50:18 by dde-jesu          #+#    #+#             */
/*   Updated: 2018/12/07 16:05:10 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/math.h"
#include <stdint.h>

t_mat4	mat4_identity(void)
{
	return ((t_mat4)((t_mat4_data) {
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	}));
}

t_mat4	mat4_mult(t_mat4 a, t_mat4 b)
{
	t_mat4		res;
	uint8_t		x;
	uint8_t		y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			res.a[y][x] = a.a[y][0] * b.a[0][x] + a.a[y][1] * b.a[1][x]
						+ a.a[y][2] * b.a[2][x] + a.a[y][3] * b.a[3][x];
			x++;
		}
		y++;
	}
	return (res);
}

t_vec3	mat4_mult_vec3(t_mat4 m, t_vec3 v)
{
	t_vec3	res;
	float	w;
	uint8_t	i;

	w = v.d.x * m.a[3][0] + v.d.y * m.a[3][1] + v.d.z * m.a[3][2] + m.a[3][3];
	i = 0;
	while (i < 3)
	{
		res.a[i] =
			(+v.d.x * m.a[i][0]
			+ v.d.y * m.a[i][1]
			+ v.d.z * m.a[i][2]
			+ m.a[i][3]) / w;
		i++;
	}
	return (res);
}

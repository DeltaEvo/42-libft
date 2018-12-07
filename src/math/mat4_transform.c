/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:52:49 by dde-jesu          #+#    #+#             */
/*   Updated: 2018/12/07 16:08:35 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/math.h"
#include <math.h>

t_mat4	mat4_scale(float x, float y, float z)
{
	return ((t_mat4)((t_mat4_data) {
		x, 0, 0, 0,
		0, y, 0, 0,
		0, 0, z, 0,
		0, 0, 0, 1
	}));
}

t_mat4	mat4_translate(float x, float y, float z)
{
	return ((t_mat4)((t_mat4_data) {
		1, 0, 0, x,
		0, 1, 0, y,
		0, 0, 1, z,
		0, 0, 0, 1
	}));
}

t_mat4	mat4_rotate_x(float angle)
{
	const float	c = cos(angle);
	const float	s = sin(angle);

	return ((t_mat4)((t_mat4_data) {
		1, 0, +0, 0,
		0, c, -s, 0,
		0, s, +c, 0,
		0, 0, +0, 1
	}));
}

t_mat4	mat4_rotate_y(float angle)
{
	const float	c = cos(angle);
	const float	s = sin(angle);

	return ((t_mat4)((t_mat4_data) {
		c, +0, s, 0,
		0, +1, 0, 0,
		-s, 0, c, 0,
		0, +0, 0, 1
	}));
}

t_mat4	mat4_rotate_z(float angle)
{
	const float	c = cos(angle);
	const float	s = sin(angle);

	return ((t_mat4)((t_mat4_data) {
		c, -s, 0, 0,
		s, +c, 0, 0,
		0, +0, 1, 0,
		0, +0, 0, 1
	}));
}

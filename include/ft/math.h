/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:45:23 by dde-jesu          #+#    #+#             */
/*   Updated: 2018/12/07 15:55:03 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_H
# define MATH_H

typedef	struct	s_mat4_data {
	float	m11;
	float	m12;
	float	m13;
	float	m14;
	float	m21;
	float	m22;
	float	m23;
	float	m24;
	float	m31;
	float	m32;
	float	m33;
	float	m34;
	float	m41;
	float	m42;
	float	m43;
	float	m44;
}				t_mat4_data;

typedef	union	u_mat4 {
	float		a[4][4];
	t_mat4_data	d;
}				t_mat4;

typedef	struct	s_vec3_data {
	float	x;
	float	y;
	float	z;
}				t_vec3_data;

typedef	union	s_vec3 {
	float		a[3];
	t_vec3_data	d;
}				t_vec3;

t_mat4			mat4_identity();
t_mat4			mat4_scale(float scaleX, float scaleY, float scaleZ);
t_mat4			mat4_translate(float x, float y, float z);
t_mat4			mat4_mult(t_mat4 a, t_mat4 b);
t_vec3			mat4_mult_vec3(t_mat4 m, t_vec3 v);
t_mat4			mat4_rotate_x(float angle);
t_mat4			mat4_rotate_y(float angle);
t_mat4			mat4_rotate_z(float angle);

#endif

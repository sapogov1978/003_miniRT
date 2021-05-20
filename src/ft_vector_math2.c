/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_math2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 00:54:50 by brattles          #+#    #+#             */
/*   Updated: 2021/05/08 02:55:05 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	vec_len(t_vec vector)
{
	return (sqrtf(powf(vector.x, 2) + powf(vector.y, 2) + powf(vector.z, 2)));
}

t_vec	vec_len_add(t_vec vector, double x)
{
	return ((t_vec){vector.x * x, \
					vector.y * x, \
					vector.z * x});
}

t_vec	vec_transfer(t_vec a, t_vec b)
{
	return (vec_nmlz(vec_diff(a, b)));
}

t_vec	equation_variable(t_vec direction, t_vec cam_origin)
{
	t_vec	equation;

	equation.x = dot(direction, direction);
	equation.y = 2. * dot(direction, cam_origin);
	equation.z = dot(cam_origin, cam_origin);
	return (equation);
}

t_vec	faceforward(t_vec ray, t_vec norm)
{
	if (dot(ray, norm) < 0)
		return (norm);
	return (vec_len_add(norm, -1));
}

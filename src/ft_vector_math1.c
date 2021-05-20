/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_math1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 00:54:50 by brattles          #+#    #+#             */
/*   Updated: 2021/05/08 02:54:08 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	vec_diff(t_vec a, t_vec b)
{
	return ((t_vec){a.x - b.x, \
					a.y - b.y, \
					a.z - b.z});
}

t_vec	vec_summ(t_vec a, t_vec b)
{
	return ((t_vec){a.x + b.x, \
					a.y + b.y, \
					a.z + b.z});
}

t_vec	vec_nmlz(t_vec vector)
{
	const float	len = vec_len(vector);

	return ((t_vec){vector.x / len, \
					vector.y / len, \
					vector.z / len});
}

double	dot(t_vec a, t_vec b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vec	cross(t_vec a, t_vec b)
{
	return ((t_vec){a.y * b.z - a.z * b.y, \
					a.z * b.x - a.x * b.z, \
					a.x * b.y - a.y * b.x});
}

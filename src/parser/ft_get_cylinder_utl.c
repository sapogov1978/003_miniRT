/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cylinder_utl.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:25:20 by brattles          #+#    #+#             */
/*   Updated: 2021/05/10 17:28:31 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_cy_point_normal(const t_geom *cy, const t_ray *ray, t_hit *hit)
{
	const double	m = dot(ray->dir, cy->normal) * hit->dstn + \
						dot(vec_diff(ray->origin, cy->origin), cy->normal);

	hit->normal = faceforward(ray->dir, \
					vec_transfer(vec_diff(hit->point, cy->origin), \
					vec_len_add(cy->normal, m)));
	hit->color = cy->color;
	hit->geom = (t_geom *)cy;
}

bool	hit_norminette_crutch(const t_geom *cy, const t_ray *ray, \
									double d, t_hit *hit)
{
	hit->dstn = d;
	hit->point = vec_summ(ray->origin, vec_len_add(ray->dir, hit->dstn));
	get_cy_point_normal(cy, ray, hit);
	return (true);
}

bool	cy_d_exp(const t_geom *cy, const t_ray *ray, double sq, double d)
{
	const t_vec	move = vec_summ(vec_len_add(cy->normal, cy->height), \
						cy->origin);

	if (dot(vec_nmlz(vec_diff(vec_summ(ray->origin, \
		vec_len_add(ray->dir, sq)), cy->origin)), cy->normal) >= EPSILON && \
		dot(vec_nmlz(vec_diff(move, vec_summ(ray->origin, \
		vec_len_add(ray->dir, sq)))), cy->normal) >= EPSILON && \
		sq < d && sq > EPSILON)
		return (true);
	return (false);
}

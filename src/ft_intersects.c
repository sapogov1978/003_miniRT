/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 16:33:48 by brattles          #+#    #+#             */
/*   Updated: 2021/05/10 20:36:27 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	intersect_all(const t_scn *scn, const t_ray *ray, t_hit *hit)
{
	t_geom	*temp;
	double	distance;

	*hit = (t_hit){.dstn = INFINITY};
	distance = INFINITY;
	temp = scn->geom;
	while (temp)
	{
		if (temp->intersect(temp, ray, &temp->hit) && temp->hit.dstn < distance)
		{
			distance = temp->hit.dstn;
			*hit = temp->hit;
		}
		temp = temp->next;
	}
	if (distance < INFINITY && distance > 0)
		return (true);
	return (false);
}

bool	first_intersect(const t_scn *scn, const t_ray *ray, double max_dst)
{
	t_geom	*temp;

	temp = scn->geom;
	while (temp)
	{
		if (temp->intersect(temp, ray, &temp->hit) && temp->hit.dstn > EPSILON \
			&& temp->hit.dstn < max_dst)
			return (true);
		temp = temp->next;
	}
	return (false);
}

static t_color	find_color_sub(t_lgts *lg, const t_scn *scn, \
								t_vec lvec, t_hit *hit)
{
	t_color		tmp;

	tmp = rgb_mult(lg->color, hit->color);
	tmp = ft_mix_color(tmp, dot(hit->normal, lvec) * lg->brightness);
	tmp = rgb_add(tmp, ft_mix_color(rgb_mult(hit->color, \
										scn->amb_color), scn->amb_brightness));
	return (tmp);
}

t_color	find_color(t_vec intersect, t_scn *scn, t_hit *hit)
{
	t_lgts	*temp;
	t_vec	lvec;
	t_color	lg_col;
	double	lvec_len;

	temp = scn->lgts;
	lg_col = (t_color){0, 0, 0};
	while (temp)
	{
		lvec = vec_diff(temp->origin, intersect);
		lvec_len = vec_len(lvec) - EPSILON;
		lvec = vec_nmlz(lvec);
		if (first_intersect(scn, &(t_ray){intersect, lvec}, lvec_len) \
			|| dot(hit->normal, lvec) < 0)
			lg_col = rgb_add(lg_col, ft_mix_color(rgb_mult(hit->color, \
								scn->amb_color), scn->amb_brightness));
		else
			lg_col = rgb_add(lg_col, find_color_sub(temp, scn, lvec, hit));
		temp = temp->next;
	}
	return (lg_col);
}

t_color	ft_intersect(t_mlx *minirt, t_vec ray)
{
	t_hit	hit;
	t_color	lg_color;

	if (intersect_all(&minirt->scn, &(t_ray){minirt->scn.cmrs->origin, ray}, \
		&hit))
	{
		lg_color = find_color(hit.point, &minirt->scn, &hit);
		return (lg_color);
	}
	return ((t_color){0, 0, 0});
}

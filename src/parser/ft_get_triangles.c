/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_triangles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 02:19:07 by brattles          #+#    #+#             */
/*   Updated: 2021/05/10 18:21:21 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	hit_normal(const t_geom *tr, const t_ray *ray, t_hit *hit)
{
	hit->normal = cross(vec_diff(tr->vertex3, tr->vertex2), \
					vec_diff(tr->vertex3, tr->vertex1));
	hit->normal = vec_nmlz(faceforward(ray->dir, hit->normal));
	hit->color = tr->color;
	hit->geom = (t_geom *)tr;
}

bool	triangle_intersect(const t_geom *tr, const t_ray *ray, t_hit *hit)
{
	t_vec		q;
	const t_vec	h = cross(ray->dir, vec_diff(tr->vertex3, tr->vertex1));
	double		auv[3];

	auv[0] = dot(vec_diff(tr->vertex2, tr->vertex1), h);
	hit_normal(tr, ray, hit);
	if (auv[0] > -EPSILON && auv[0] < EPSILON)
		return (false);
	auv[1] = 1 / auv[0] * (dot(vec_diff(ray->origin, tr->vertex1), h));
	if (auv[1] < EPSILON || auv[1] > 1.0)
		return (false);
	q = cross(vec_diff(ray->origin, tr->vertex1), \
		vec_diff(tr->vertex2, tr->vertex1));
	auv[2] = 1 / auv[0] * dot(ray->dir, q);
	if (auv[2] < EPSILON || auv[1] + auv[2] > 1.0)
		return (false);
	hit->dstn = 1 / auv[0] * dot(vec_diff(tr->vertex3, tr->vertex1), q);
	if (hit->dstn < EPSILON)
		return (false);
	hit->point = vec_summ(ray->origin, vec_len_add(ray->dir, hit->dstn));
	return (true);
}

static void 	fill_triangle(t_scn *scn, t_geom *triangle, char **splitted)
{
	char	**triangle_color;

	if (ft_split_line_qty(splitted) != 5)
		ft_panic("Triangle format: tr [coords1 x,y,z] [coords2 x,y,z] \
			[cords3 x,y,z] [color R,G,B]");
	ft_get_vector(&triangle->vertex1, splitted[1]);
	ft_get_vector(&triangle->vertex2, splitted[2]);
	ft_get_vector(&triangle->vertex3, splitted[3]);
	triangle_color = ft_split(splitted[4], ',');
	if (ft_split_line_qty(triangle_color) != 3)
		ft_panic("Colors shold have 3 components - R(ed), G(reen), B(lue)");
	triangle->color = (t_color){ft_atoi(triangle_color[0]), \
								ft_atoi(triangle_color[1]), \
								ft_atoi(triangle_color[2])};
	if (ft_is_false_color(triangle->color))
		ft_panic("Colors should be in range: [R 0-255,G 0-255,B 0-255]");
	ft_putmmrback(triangle_color);
	triangle->type = E_TRIANGLE;
	scn->geom_total += 1;
	triangle->id = scn->geom_total;
	triangle->intersect = triangle_intersect;
}

void	ft_get_triangle(t_scn *scn, t_geom **triangle, char **splitted)
{
	t_geom	*temp;

	if (!(*triangle))
	{
		*triangle = ft_calloc(1, sizeof(t_geom));
		fill_triangle(scn, *triangle, splitted);
	}
	else
	{
		temp = *triangle;
		while ((*triangle)->next)
			*triangle = (*triangle)->next;
		(*triangle)->next = ft_calloc(1, sizeof(t_geom));
		fill_triangle(scn, (*triangle)->next, splitted);
		*triangle = temp;
	}
}

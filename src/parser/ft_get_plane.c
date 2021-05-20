/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 23:54:16 by brattles          #+#    #+#             */
/*   Updated: 2021/05/10 15:24:43 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	plane_intersect(const t_geom *pl, const t_ray *ray, t_hit *hit)
{
	double		a;
	double		b;

	a = dot(vec_diff(ray->origin, pl->origin), pl->normal);
	b = dot(ray->dir, pl->normal);
	hit->dstn = -(a / b);
	if (hit->dstn < EPSILON)
		return (false);
	hit->point = vec_summ(ray->origin, vec_len_add(ray->dir, hit->dstn));
	if (b > EPSILON)
		hit->normal = pl->normal;
	else
		hit->normal = vec_len_add(pl->normal, -copysignf(1, b));
	hit->geom = (t_geom *)pl;
	hit->color = pl->color;
	return (true);
}

static void	fill_plane(t_scn *scn, t_geom *plane, char **splitted)
{
	char	**plane_color;

	if (ft_split_line_qty(splitted) != 4)
		ft_panic("Plane format: pl [coords x,y,z] [normal x,y,z] \
			[color R,G,B]");
	ft_get_vector(&plane->origin, splitted[1]);
	ft_get_vector(&plane->normal, splitted[2]);
	plane->normal = vec_nmlz(plane->normal);
	plane_color = ft_split(splitted[3], ',');
	if (ft_split_line_qty(plane_color) != 3)
		ft_panic("Colors shold have 3 components - R(ed), G(reen), B(lue)");
	plane->color = (t_color){ft_atoi(plane_color[0]), \
							ft_atoi(plane_color[1]), \
							ft_atoi(plane_color[2])};
	if (ft_is_false_color(plane->color))
		ft_panic("Colors should be in range: [R 0-255,G 0-255,B 0-255]");
	ft_putmmrback(plane_color);
	scn->geom_total += 1;
	plane->id = scn->geom_total;
	plane->intersect = plane_intersect;
}

void	ft_get_plane(t_scn *scn, t_geom **plane, char **splitted)
{
	t_geom	*temp;

	if (!(*plane))
	{
		*plane = ft_calloc(1, sizeof(t_geom));
		fill_plane(scn, *plane, splitted);
	}
	else
	{
		temp = *plane;
		while ((*plane)->next)
			*plane = (*plane)->next;
		(*plane)->next = ft_calloc(1, sizeof(t_geom));
		fill_plane(scn, (*plane)->next, splitted);
		*plane = temp;
	}
}

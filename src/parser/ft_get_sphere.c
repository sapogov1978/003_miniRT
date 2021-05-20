/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 02:35:06 by brattles          #+#    #+#             */
/*   Updated: 2021/05/10 15:23:19 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	sphere_intersect(const t_geom *sp, const t_ray *ray, t_hit *hit)
{
	const t_vec		a = vec_diff(ray->origin, sp->origin);
	const double	b = 2 * dot(a, ray->dir);
	const double	c = dot(a, a) - powf(sp->diameter * 0.5, 2);
	double			d;

	d = powf(b, 2) - 4 * c;
	if (d < EPSILON)
		return (false);
	if (vec_len(a) > sp->diameter * 0.5)
	{
		hit->dstn = (-b - sqrtf(d)) * 0.5;
		hit->point = vec_summ(ray->origin, vec_len_add(ray->dir, \
								hit->dstn - EPSILON));
		hit->normal = vec_transfer(hit->point, sp->origin);
	}
	else
	{
		hit->dstn = (-b + sqrtf(d)) * 0.5;
		hit->point = vec_summ(ray->origin, vec_len_add(ray->dir, \
								hit->dstn - EPSILON));
		hit->normal = vec_transfer(sp->origin, hit->point);
	}
	hit->color = sp->color;
	hit->geom = (t_geom *)sp;
	return (true);
}

static void	fill_sphere(t_scn *scn, t_geom *sphere, char **splitted)
{
	char	**sphere_color;

	if (ft_split_line_qty(splitted) != 4)
		ft_panic("Sphere format: sp [origin x,y,z] [diameter] [R,G,B]");
	ft_get_vector(&sphere->origin, splitted[1]);
	sphere->diameter = ft_atof(splitted[2]);
	sphere_color = ft_split(splitted[3], ',');
	if (ft_split_line_qty(sphere_color) != 3)
		ft_panic("Colors shold have 3 components - R(ed), G(reen), B(lue)");
	sphere->color = (t_color){ft_atoi(sphere_color[0]), \
							ft_atoi(sphere_color[1]), \
							ft_atoi(sphere_color[2])};
	if (ft_is_false_color(sphere->color))
		ft_panic("Colors should be in range: [R 0-255,G 0-255,B 0-255]");
	ft_putmmrback(sphere_color);
	sphere->type = E_SPHERE;
	scn->geom_total += 1;
	sphere->id = scn->geom_total;
	sphere->intersect = sphere_intersect;
}

void	ft_get_sphere(t_scn *scn, t_geom **sphere, char **splitted)
{
	t_geom	*temp;

	if (!(*sphere))
	{
		*sphere = ft_calloc(1, sizeof(t_geom));
		fill_sphere(scn, *sphere, splitted);
	}
	else
	{
		temp = *sphere;
		while ((*sphere)->next)
			*sphere = (*sphere)->next;
		(*sphere)->next = ft_calloc(1, sizeof(t_geom));
		fill_sphere(scn, (*sphere)->next, splitted);
		*sphere = temp;
	}
}

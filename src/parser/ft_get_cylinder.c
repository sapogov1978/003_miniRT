/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 01:24:10 by brattles          #+#    #+#             */
/*   Updated: 2021/05/10 17:24:54 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	cylinder_intersect(const t_geom *cy, const t_ray *ray, t_hit *hit)
{
	const t_vec	x = vec_diff(ray->origin, cy->origin);
	t_vec		var;
	double		d[2];
	double		sq[3];

	d[0] = dot(ray->dir, cy->normal);
	d[1] = dot(x, cy->normal);
	var.x = dot(ray->dir, ray->dir) - powf(d[0], 2.);
	var.y = 2 * (dot(ray->dir, x) - d[0] * d[1]);
	var.z = dot(x, x) - powf(d[1], 2.) - powf(cy->diameter * 0.5, 2.);
	if (powf(var.y, 2) - 4 * var.x * var.z < EPSILON)
		return (false);
	sq[0] = sqrt(powf(var.y, 2) - 4 * var.x * var.z);
	sq[1] = (-var.y + sq[0]) / (2 * var.x);
	sq[2] = (-var.y - sq[0]) / (2 * var.x);
	d[0] = INFINITY;
	if (cy_d_exp(cy, ray, sq[1], d[0]))
		d[0] = sq[1];
	if (cy_d_exp(cy, ray, sq[2], d[0]))
		d[0] = sq[2];
	if (d[0] == sq[2] || d[0] == sq[1])
		return (hit_norminette_crutch(cy, ray, d[0], hit));
	return (false);
}

static void	fill_cylinder (t_scn *scn, t_geom *cylinder, char **splitted)
{
	char	**cylinder_color;

	if (ft_split_line_qty(splitted) != 6)
		ft_panic("Cylinder format: cy [coords x,y,z] [normal x,y,z] \
			[diameter d] [height h] [color R,G,B]");
	ft_get_vector(&cylinder->origin, splitted[1]);
	ft_get_vector(&cylinder->normal, splitted[2]);
	cylinder->normal = vec_nmlz(cylinder->normal);
	cylinder->diameter = ft_atof(splitted[3]);
	cylinder->height = ft_atof(splitted[4]);
	cylinder_color = ft_split(splitted[5], ',');
	if (ft_split_line_qty(cylinder_color) != 3)
		ft_panic("Colors shold have 3 components - R(ed), G(reen), B(lue)");
	cylinder->color = (t_color){ft_atoi(cylinder_color[0]), \
								ft_atoi(cylinder_color[1]), \
								ft_atoi(cylinder_color[2])};
	if (ft_is_false_color(cylinder->color))
		ft_panic("Colors should be in range: [R 0-255,G 0-255,B 0-255]");
	ft_putmmrback(cylinder_color);
	cylinder->type = E_CYLINDER;
	scn->geom_total += 1;
	cylinder->id = scn->geom_total;
	cylinder->intersect = cylinder_intersect;
}

void	ft_get_cylinder(t_scn *scn, t_geom **cylinder, char **splitted)
{
	t_geom	*temp;

	if (!(*cylinder))
	{
		*cylinder = ft_calloc(1, sizeof(t_geom));
		fill_cylinder(scn, *cylinder, splitted);
	}
	else
	{
		temp = *cylinder;
		while ((*cylinder)->next)
			*cylinder = (*cylinder)->next;
		(*cylinder)->next = ft_calloc(1, sizeof(t_geom));
		fill_cylinder(scn, (*cylinder)->next, splitted);
		*cylinder = temp;
	}
}

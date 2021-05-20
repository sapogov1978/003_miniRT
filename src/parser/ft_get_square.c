/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 01:44:09 by brattles          #+#    #+#             */
/*   Updated: 2021/05/10 17:20:02 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	sub_sq(const t_geom *sq, const t_ray *ray, t_hit *hit)
{
	hit->normal = vec_nmlz(faceforward(ray->dir, sq->normal));
	hit->color = sq->color;
	hit->geom = (t_geom *)sq;
	return (true);
}

bool	square_intersect(const t_geom *sq, const t_ray *ray, t_hit *hit)
{
	t_vec	a;
	t_vec	b;
	t_vec	pt_o;
	double	len;

	if (!plane_intersect(sq, ray, hit))
		return (false);
	if (sq->normal.x == 0. && (sq->normal.y == -1. || sq->normal.y == 1.) \
		&& sq->normal.z == 0.)
		a = (t_vec){0, 0, 1};
	else
		a = (t_vec){0, 1, 0};
	pt_o = vec_diff(hit->point, sq->origin);
	len = vec_len(pt_o);
	pt_o = vec_nmlz(pt_o);
	a = vec_nmlz(cross(sq->normal, a));
	b = vec_nmlz(cross(sq->normal, a));
	if (dot(a, pt_o) < 0.0)
		a = vec_len_add(a, -1);
	if (dot(b, pt_o) < 0.0)
		b = vec_len_add(b, -1);
	if (dot(a, pt_o) * len <= sq->side * 0.5 && \
		dot(b, pt_o) * len <= sq->side * 0.5)
		return (sub_sq(sq, ray, hit));
	return (false);
}

static void	fill_square(t_scn *scn, t_geom *square, char **splitted)
{
	char	**square_color;

	if (ft_split_line_qty(splitted) != 5)
		ft_panic("Square format: sq [origin x,y,z] [normal x,y,z] [side s] \
			[color R,G,B]");
	ft_get_vector(&square->origin, splitted[1]);
	ft_get_vector(&square->normal, splitted[2]);
	vec_nmlz(square->normal);
	square->side = ft_atof(splitted[3]);
	square_color = ft_split(splitted[4], ',');
	if (ft_split_line_qty(square_color) != 3)
		ft_panic("Colors shold have 3 components - R(ed), G(reen), B(lue)");
	square->color = (t_color){ft_atoi(square_color[0]), \
							ft_atoi(square_color[1]), \
							ft_atoi(square_color[2])};
	if (ft_is_false_color(square->color))
		ft_panic("Colors should be in range: [R 0-255,G 0-255,B 0-255]");
	ft_putmmrback(square_color);
	square->type = E_SQUARE;
	scn->geom_total += 1;
	square->id = scn->geom_total;
	square->intersect = square_intersect;
}

void	ft_get_square(t_scn *scn, t_geom **square, char **splitted)
{
	t_geom	*temp;

	if (!(*square))
	{
		*square = ft_calloc(1, sizeof(t_geom));
		fill_square(scn, *square, splitted);
	}
	else
	{
		temp = *square;
		while ((*square)->next)
			*square = (*square)->next;
		(*square)->next = ft_calloc(1, sizeof(t_geom));
		fill_square(scn, (*square)->next, splitted);
		*square = temp;
	}
}

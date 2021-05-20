/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cameras.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 23:35:59 by brattles          #+#    #+#             */
/*   Updated: 2021/05/10 15:56:02 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	basis_apply(const t_basis *basis, t_vec *v)
{
	const t_vec	x = vec_len_add(basis->xaxis, v->x);
	const t_vec	y = vec_len_add(basis->yaxis, v->y);
	const t_vec	z = vec_len_add(basis->zaxis, v->z);

	*v = vec_summ(vec_summ(x, y), z);
}

static void	orthonormal(t_vec n, t_vec *b1, t_vec *b2)
{
	const double	s = copysignf(1.0, n.z);
	const double	a = -1.0 / (s + n.z);
	const double	b = n.x * n.y * a;

	b1->x = 1.0 + s * powf(n.x, 2) * a;
	b1->y = s * b;
	b1->z = -s * n.x;
	b2->x = b;
	b2->y = s + powf(n.y, 2) * a;
	b2->z = -n.y;
}

t_basis	*basis_create(t_basis *basis, t_vec direction)
{
	basis->zaxis = direction;
	orthonormal(basis->zaxis, &basis->xaxis, &basis->yaxis);
	return (basis);
}

static void	fill_camera(t_cmrs *camera, char **splitted)
{
	if (ft_split_line_qty(splitted) != 4)
		ft_panic("Cameras format: c [coords x,y,z] \
			[orientation x,y,z in range -1 - 1] [FOV in range 0 - 180]");
	ft_get_vector(&camera->origin, splitted[1]);
	ft_get_vector(&camera->direction, splitted[2]);
	camera->direction = vec_nmlz(camera->direction);
	if (camera->direction.x == 0 && camera->direction.y == 0 && \
		camera->direction.z == 0)
		ft_panic("Your camera looking nowhere. \
			Please correct camera direction");
	basis_create(&camera->basis, camera->direction);
	camera->fov = ft_atoi(splitted[3]);
	if (camera->fov < 0 || camera->fov > 180)
		ft_panic("Camera FOV should be in range [0 - 180].");
}

void	ft_get_cameras(t_cmrs **camera, char **splitted)
{
	t_cmrs	*temp;

	if (!(*camera))
	{
		*camera = ft_calloc(1, sizeof(t_cmrs));
		fill_camera(*camera, splitted);
	}
	else
	{
		temp = *camera;
		while ((*camera)->next)
			*camera = (*camera)->next;
		(*camera)->next = ft_calloc(1, sizeof(t_cmrs));
		fill_camera((*camera)->next, splitted);
		*camera = temp;
	}
}

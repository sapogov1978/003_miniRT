/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rendering.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 00:38:08 by brattles          #+#    #+#             */
/*   Updated: 2021/05/10 16:33:34 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	pixel_put(t_mlx *minirt, int x, int y, int color)
{
	const size_t	offset = y * minirt->img.size_line + x * sizeof(int);

	*(int *)(minirt->img.data + offset) = color;
}

static void	rays(t_mlx *minirt, int x, int y, t_vec *ray)
{
	ray->z = minirt->win.x_res / (2 * tanf(minirt->scn.cmrs->fov * \
				0.5 * M_PI / 180));
	ray->y = -y + minirt->win.y_res * 0.5;
	ray->x = x - minirt->win.x_res * 0.5;
}

void	ft_rendering(t_mlx *minirt)
{
	int				x;
	int				y;
	t_ray			ray;
	t_color			color;

	y = 0;
	while (y < minirt->win.y_res)
	{
		x = 0;
		while (x < minirt->win.x_res)
		{
			rays(minirt, x, y, &ray.dir);
			basis_apply(&minirt->scn.cmrs->basis, &ray.dir);
			ray.dir = vec_nmlz(ray.dir);
			color = ft_intersect(minirt, ray.dir);
			pixel_put(minirt, x, y, vec_to_int(color));
			x++;
		}
		y++;
	}
	if (minirt->save_flag)
		save(minirt);
	mlx_do_sync(minirt->ptr);
	mlx_put_image_to_window(minirt->ptr, minirt->win.ptr, \
							minirt->img.ptr, 0, 0);
}

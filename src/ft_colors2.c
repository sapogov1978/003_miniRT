/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 13:51:34 by brattles          #+#    #+#             */
/*   Updated: 2021/05/10 16:04:00 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	mix_color(t_color a, t_color b)
{
	t_color	color;
	t_vec	min_mix;
	t_vec	max_mix;
	float	brightnes;

	min_mix.x = ft_minf(a.x, ft_minf(a.y, a.z));
	min_mix.y = ft_minf(b.x, ft_minf(b.y, b.z));
	min_mix.z = (min_mix.x + min_mix.y) * 0.5;
	max_mix.x = ft_maxf(a.x, ft_maxf(a.y, a.z));
	max_mix.y = ft_maxf(b.x, ft_maxf(b.y, b.z));
	a.x -= min_mix.x;
	a.y -= min_mix.x;
	a.z -= min_mix.x;
	b.x -= min_mix.y;
	b.y -= min_mix.y;
	b.z -= min_mix.y;
	brightnes = (max_mix.x + max_mix.y) / (2 * 255.0);
	color = (t_color){((a.x + b.x) * brightnes), ((a.y + b.y) * brightnes), \
						((a.z + b.z) * brightnes)};
	color.x += min_mix.z;
	color.y += min_mix.z;
	color.z += min_mix.z;
	return (color);
}

t_color	rgb_add(t_color rgb1, t_color rgb2)
{
	return ((t_color){(clamp(rgb1.x + rgb2.x, 0, 255)), \
						(clamp(rgb1.y + rgb2.y, 0, 255)), \
						(clamp(rgb1.z + rgb2.z, 0, 255))});
}

t_color	rgb_mult(t_color rgb1, t_color rgb2)
{
	return ((t_color){rgb1.x * rgb2.x / 255, \
						rgb1.y * rgb2.y / 255, \
						rgb1.z * rgb2.z / 255});
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 13:51:34 by brattles          #+#    #+#             */
/*   Updated: 2021/05/08 02:29:39 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	ft_is_false_color(t_color color)
{
	return (color.x < 0 || color.x > 255 || color.y < 0 || color.y > 255 \
			|| color.z < 0 || color.z > 255);
}

int	clamp(int value, int min, int max)
{
	if (value >= max)
		return (max);
	if (value <= min)
		return (min);
	return (value);
}

double	clampf(double value, double min, double max)
{
	if (value >= max)
		return (max);
	if (value <= min)
		return (min);
	return (value);
}

t_color	ft_mix_color(t_color color, double intensity)
{
	t_color	mix;

	mix.x = clampf(color.x * intensity, 0, 255);
	mix.y = clampf(color.y * intensity, 0, 255);
	mix.z = clampf(color.z * intensity, 0, 255);
	return (mix);
}

int	vec_to_int(t_color c)
{
	return (((int)c.x << 16 | (int)c.y << 8 | (int)c.z));
}

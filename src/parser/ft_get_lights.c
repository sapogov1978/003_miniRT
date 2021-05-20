/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_lights.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 01:20:09 by brattles          #+#    #+#             */
/*   Updated: 2021/05/10 10:53:45 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	fill_light(t_mlx *minirt, t_lgts *light, char **splitted)
{
	char	**lgt_color;

	if (ft_split_line_qty(splitted) != 4)
		ft_panic("Lights format:\nl [Coords x,y,z] [brightness] [color R,G,B]");
	ft_get_vector(&light->origin, splitted[1]);
	light->brightness = ft_atof(splitted[2]);
	lgt_color = ft_split(splitted[3], ',');
	if (ft_split_line_qty(lgt_color) != 3)
		ft_panic("Colors shold have 3 components - R(ed), G(reen), B(lue)");
	light->color = (t_color){ft_atoi(lgt_color[0]), \
							ft_atoi(lgt_color[1]), \
							ft_atoi(lgt_color[2])};
	if (ft_is_false_color(light->color))
		ft_panic("Colors should be in range: [R 0-255,G 0-255,B 0-255]");
	ft_putmmrback(lgt_color);
	minirt->scn.lights_total += 1;
}

void	ft_get_lights(t_mlx *minirt, t_lgts **light, char **splitted)
{
	t_lgts	*temp;

	if (!(*light))
	{
		*light = ft_calloc(1, sizeof(t_lgts));
		fill_light(minirt, *light, splitted);
	}
	else
	{
		temp = *light;
		while ((*light)->next)
			*light = (*light)->next;
		(*light)->next = ft_calloc(1, sizeof(t_lgts));
		fill_light(minirt, (*light)->next, splitted);
		*light = temp;
	}
}

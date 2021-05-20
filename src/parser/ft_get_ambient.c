/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_ambient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 18:03:10 by brattles          #+#    #+#             */
/*   Updated: 2021/05/10 10:52:49 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_get_ambient(t_mlx *minirt, char **splitted)
{
	char	**amb_color;

	if (minirt->scn.amb_color.x != -1)
		ft_panic("Ambient light can be specified only once");
	if (ft_split_line_qty(splitted) != 3)
		ft_panic("Ambient light format: A [brightness 0.0-1.0] \
			[R 0-255,G 0-255,B 0-255]");
	minirt->scn.amb_brightness = ft_atof(splitted[1]);
	if (minirt->scn.amb_brightness < 0 || minirt->scn.amb_brightness > 1)
		ft_panic("Ambient light format: A [brightness 0.0-1.0] \
			[R 0-255,G 0-255,B 0-255]");
	amb_color = ft_split(splitted[2], ',');
	if (ft_split_line_qty(amb_color) != 3)
		ft_panic("Colors shold have 3 components - R(ed), G(reen), B(lue)");
	minirt->scn.amb_color = (t_color){ft_atoi(amb_color[0]), \
									ft_atoi(amb_color[1]), \
									ft_atoi(amb_color[2])};
	if (ft_is_false_color(minirt->scn.amb_color))
		ft_panic("Colors should be in range: [R 0-255,G 0-255,B 0-255]");
	ft_putmmrback(amb_color);
}

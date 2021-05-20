/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 00:36:25 by brattles          #+#    #+#             */
/*   Updated: 2021/05/10 11:09:11 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_get_vector(t_vec *point, char *coords)
{
	char	**xyz;

	xyz = ft_split(coords, ',');
	if (ft_split_line_qty(xyz) != 3)
		ft_panic("Coordinates should be in X,Y,Z format");
	point->x = ft_atof(xyz[0]);
	point->y = ft_atof(xyz[1]);
	point->z = ft_atof(xyz[2]);
	ft_putmmrback(xyz);
}

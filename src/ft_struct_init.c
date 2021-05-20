/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 22:24:02 by brattles          #+#    #+#             */
/*   Updated: 2021/05/09 21:59:28 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_mlx	*ft_struct_init(char **argv)
{
	t_mlx		*minirt;

	minirt = ft_calloc(1, sizeof(t_mlx));
	if (!minirt)
		ft_panic("Not enough memory");
	minirt->ptr = NULL;
	if (argv[2] && ft_strcmp(argv[2], "--save") == 0)
	{
		minirt->save_flag = 1;
		minirt->plot = (void *)(save);
	}
	else
	{
		minirt->save_flag = 0;
		minirt->plot = (void *)(pixel_put);
	}
	minirt->win = (t_win){NULL, 0, 0, 0, 0, 0, 0};
	minirt->scn.amb_brightness = 0;
	minirt->scn.amb_color = (t_color){-1, -1, -1};
	minirt->scn.lights_total = 0;
	minirt->scn.geom_total = 0;
	return (minirt);
}

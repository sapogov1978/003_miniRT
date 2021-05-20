/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_resolution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 23:12:31 by brattles          #+#    #+#             */
/*   Updated: 2021/05/10 18:13:02 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	too_high(t_mlx *minirt, float x_mltp)
{
	minirt->win.x_res = minirt->win.max_x_size - 6;
	minirt->win.y_res = (minirt->win.y_res_rt * x_mltp) - (6 * x_mltp);
	if (minirt->win.x_res <= 0)
		minirt->win.x_res = 100;
	if (minirt->win.y_res <= 0)
		minirt->win.y_res = 100;
}

static void	too_wide(t_mlx *minirt, float y_mltp)
{
	minirt->win.x_res = (minirt->win.x_res_rt * y_mltp) - (62 * y_mltp);
	minirt->win.y_res = minirt->win.max_y_size - 62;
	if (minirt->win.x_res <= 0)
		minirt->win.x_res = 100;
	if (minirt->win.y_res <= 0)
		minirt->win.y_res = 100;
}

static void	just_too_much(t_mlx *minirt, float x_mltp, float y_mltp)
{
	minirt->win.x_res = (minirt->win.x_res_rt * x_mltp) - (6 * x_mltp);
	minirt->win.y_res = (minirt->win.y_res_rt * y_mltp) - (62 * y_mltp);
	if (minirt->win.x_res <= 0)
		minirt->win.x_res = 100;
	if (minirt->win.y_res <= 0)
		minirt->win.y_res = 100;
}

static void	ft_get_resize(t_mlx *minirt)
{
	float	x_mltp;
	float	y_mltp;

	mlx_get_screen_size(minirt->ptr, &minirt->win.max_x_size, \
						&minirt->win.max_y_size);
	if ((((int)minirt->win.x_res_rt >= minirt->win.max_x_size) || \
		((int)minirt->win.y_res_rt >= minirt->win.max_y_size)) && \
		minirt->save_flag == 0)
	{
		x_mltp = (float)minirt->win.max_x_size / minirt->win.x_res_rt;
		y_mltp = (float)minirt->win.max_y_size / minirt->win.y_res_rt;
		if (x_mltp < y_mltp)
			too_high (minirt, x_mltp);
		else if (y_mltp < x_mltp)
			too_wide (minirt, y_mltp);
		else
			just_too_much(minirt, x_mltp, y_mltp);
	}
	else
	{
		minirt->win.x_res = minirt->win.x_res_rt;
		minirt->win.y_res = minirt->win.y_res_rt;
	}
}

void	ft_get_resolution(t_mlx *minirt, char **splitted)
{
	if (minirt->win.x_res_rt != 0 || minirt->win.y_res_rt != 0)
		ft_panic("Double resolution. You can only specify resolution once");
	if (ft_split_line_qty(splitted) != 3)
		ft_panic("Resolution should contain height and width");
	minirt->win.x_res_rt = ft_atoi(splitted[1]);
	minirt->win.y_res_rt = ft_atoi(splitted[2]);
	if (minirt->win.x_res_rt <= 0 || minirt->win.y_res_rt <= 0)
		ft_panic("You have to specify positive window width and height.");
	if (minirt->win.x_res_rt >= INT_MAX || minirt->win.y_res_rt >= INT_MAX)
		ft_panic("What did you smoke today? Please, share!");
	ft_get_resize(minirt);
}

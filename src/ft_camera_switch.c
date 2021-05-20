/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera_switch.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 01:10:02 by brattles          #+#    #+#             */
/*   Updated: 2021/04/17 12:57:39 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	camera_switch(t_mlx *minirt, t_cmrs **camera)
{
	static t_cmrs	*start_camera;
	t_cmrs			*temp_camera;

	if (!start_camera)
		start_camera = *camera;
	temp_camera = *camera;
	if (temp_camera->next == NULL)
		*camera = start_camera;
	else
		*camera = temp_camera->next;
	ft_rendering(minirt);
}

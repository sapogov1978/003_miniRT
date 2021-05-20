/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 02:37:25 by brattles          #+#    #+#             */
/*   Updated: 2021/05/09 22:52:17 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	unload(t_mlx *minirt)
{
	mlx_destroy_image(minirt->ptr, minirt->img.ptr);
	mlx_destroy_window(minirt->ptr, minirt->win.ptr);
	exit(EXIT_SUCCESS);
}

int	on_keydown(int key, t_mlx *minirt)
{
	if (key == KEY_ESC)
		unload(minirt);
	if (key == KEY_APOS)
		camera_switch(minirt, &minirt->scn.cmrs);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	*minirt;
	int		fd;

	fd = ft_entry_check(argc, argv);
	minirt = ft_struct_init(argv);
	minirt->ptr = mlx_init();
	if (!minirt->ptr)
		ft_panic("MLX library initialization failed.");
	minirt->scn.scn_name = ft_get_scene_name(argv);
	ft_rtparser(fd, minirt);
	ft_light_nrmlz(&minirt->scn);
	if (minirt->save_flag == 0)
		minirt->win.ptr = mlx_new_window(minirt->ptr, minirt->win.x_res, \
							minirt->win.y_res, "21school brattles miniRT");
	minirt->img.ptr = mlx_new_image(minirt->ptr, minirt->win.x_res, \
						minirt->win.y_res);
	minirt->img.data = mlx_get_data_addr(minirt->img.ptr, &minirt->img.bpp, \
						&minirt->img.size_line, &minirt->img.endian);
	ft_rendering(minirt);
	mlx_hook(minirt->win.ptr, DESTROY, 1L << 17, (int (*)())unload, minirt);
	mlx_hook(minirt->win.ptr, KEY_DOWN, 1, (int (*)())on_keydown, minirt);
	mlx_loop(minirt->ptr);
	return (0);
}

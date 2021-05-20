/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_bmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:07:00 by brattles          #+#    #+#             */
/*   Updated: 2021/05/10 09:57:15 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	open_bmpfile(t_mlx *minirt)
{
	char	*filename;
	char	*fullpath;

	filename = ft_strjoin(minirt->scn.scn_name, ".bmp");
	fullpath = ft_strjoin("renders/", filename);
	free(filename);
	filename = NULL;
	minirt->save_fd = open(fullpath, O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (minirt->save_fd == -1)
		ft_panic("File couldn't be saved");
	free(fullpath);
	fullpath = NULL;
}

static void	make_header(t_mlx *minirt, unsigned char *file_header, int size)
{
	file_header[0] = 'B';
	file_header[1] = 'M';
	file_header[2] = (unsigned char)(size);
	file_header[3] = (unsigned char)(size >> 8);
	file_header[4] = (unsigned char)(size >> 16);
	file_header[5] = (unsigned char)(size >> 24);
	file_header[10] = 54;
	file_header[14] = 40;
	file_header[18] = (unsigned char)(minirt->win.x_res);
	file_header[19] = (unsigned char)(minirt->win.x_res >> 8);
	file_header[20] = (unsigned char)(minirt->win.x_res >> 16);
	file_header[21] = (unsigned char)(minirt->win.x_res >> 24);
	file_header[22] = (unsigned char)(minirt->win.y_res);
	file_header[23] = (unsigned char)(minirt->win.y_res >> 8);
	file_header[24] = (unsigned char)(minirt->win.y_res >> 16);
	file_header[25] = (unsigned char)(minirt->win.y_res >> 24);
	file_header[26] = 1;
	file_header[28] = minirt->img.bpp;
}

void	save(t_mlx *minirt)
{
	int				count;
	int				file_size;
	unsigned char	file_header[54];
	int				y_res;

	count = 0;
	file_size = 54 + (minirt->img.bpp / 8) * minirt->win.x_res_rt * \
				minirt->win.y_res_rt;
	ft_bzero(file_header, 54);
	make_header(minirt, file_header, file_size);
	open_bmpfile(minirt);
	count = write(minirt->save_fd, file_header, 54);
	y_res = minirt->win.y_res_rt;
	while (y_res--)
		count += write(minirt->save_fd, ((char *)minirt->img.data + \
					(minirt->img.bpp / 8) * minirt->win.x_res_rt * y_res), \
					((minirt->img.bpp / 8) * minirt->win.x_res_rt));
	close(minirt->save_fd);
	if (count != file_size)
		ft_panic("Error while saving file");
	exit(EXIT_SUCCESS);
}

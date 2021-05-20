/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rtparser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 17:56:18 by brattles          #+#    #+#             */
/*   Updated: 2021/05/10 18:36:50 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_split_line_qty(char **splitted)
{
	int	i;

	i = 0;
	while (splitted[i])
		i++;
	return (i);
}

static void	ft_parse_line(t_mlx *minirt, char **splitted)
{
	if (ft_split_line_qty(splitted) == 0)
		return ;
	else if (ft_split_line_qty(splitted) < 2)
		ft_panic("Unknown element in the scene, incomplete line");
	if (ft_memcmp(splitted[0], "R", 2) == 0)
		ft_get_resolution(minirt, splitted);
	else if (ft_memcmp(splitted[0], "A", 2) == 0)
		ft_get_ambient(minirt, splitted);
	else if (ft_memcmp(splitted[0], "c", 2) == 0)
		ft_get_cameras(&minirt->scn.cmrs, splitted);
	else if (ft_memcmp(splitted[0], "l", 2) == 0)
		ft_get_lights(minirt, &minirt->scn.lgts, splitted);
	else if (ft_memcmp(splitted[0], "pl", 3) == 0)
		ft_get_plane(&minirt->scn, &minirt->scn.geom, splitted);
	else if (ft_memcmp(splitted[0], "sp", 3) == 0)
		ft_get_sphere(&minirt->scn, &minirt->scn.geom, splitted);
	else if (ft_memcmp(splitted[0], "cy", 3) == 0)
		ft_get_cylinder(&minirt->scn, &minirt->scn.geom, splitted);
	else if (ft_memcmp(splitted[0], "sq", 3) == 0)
		ft_get_square(&minirt->scn, &minirt->scn.geom, splitted);
	else if (ft_memcmp(splitted[0], "tr", 3) == 0)
		ft_get_triangle(&minirt->scn, &minirt->scn.geom, splitted);
	else
		ft_panic("Unknown element in the scene");
}

static int	ft_rt_allowed_symbol(char c)
{
	if (ft_isspace (c) || c == '.' || c == ',' || c == '-' || ft_isdigit(c))
		return (1);
	return (0);
}

static int	ft_line_check(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if ((ft_rt_allowed_symbol(line[i]) == 0) && i > 2)
			return (0);
		i++;
	}
	return (1);
}

void	ft_rtparser(int fd, t_mlx *minirt)
{
	int		ret;
	char	*line;
	char	**splitted;

	line = NULL;
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		splitted = ft_split(line, ' ');
		if (ft_line_check(line) == 0)
			ft_panic("Forbidden symbols in the rt file");
		ft_parse_line(minirt, splitted);
		ft_putmmrback(splitted);
		free(line);
		line = NULL;
	}
	close(fd);
}

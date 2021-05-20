/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_scene_name.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:51:15 by brattles          #+#    #+#             */
/*   Updated: 2021/05/10 11:05:27 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	*ft_get_scene_name(char **argv)
{
	char	**first_split;
	char	**second_split;
	char	*scene_name;

	first_split = ft_split(argv[1], '.');
	second_split = ft_split(first_split[0], '/');
	ft_putmmrback(first_split);
	if (ft_split_line_qty(second_split) > 1)
		scene_name = second_split[ft_split_line_qty(second_split) - 1];
	else
		scene_name = second_split[0];
	ft_putmmrback(second_split);
	return (scene_name);
}

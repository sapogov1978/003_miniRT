/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_math3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 11:07:53 by brattles          #+#    #+#             */
/*   Updated: 2021/05/10 15:55:20 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	mltp(t_vec a, t_vec b)
{
	return ((t_vec){a.x * b.x, \
					a.y * b.y, \
					a.z * b.z});
}

t_vec	dvsn(t_vec a, double b)
{
	return ((t_vec){a.x / b, \
					a.y / b, \
					a.z / b});
}

float	ft_maxf(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

float	ft_minf(float a, float b)
{
	if (a < b)
		return (a);
	return (b);
}

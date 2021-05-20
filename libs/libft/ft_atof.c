/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 18:17:46 by brattles          #+#    #+#             */
/*   Updated: 2021/04/22 20:05:50 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_atof_sub(int *i, char *line, double *float_value)
{
	int	j;

	j = 10;
	while (line[*i] && line[*i] >= '0' && line[*i] <= '9')
	{
		*float_value *= 10;
		*float_value += line[*i] - '0';
		++(*i);
	}
	if (line[*i] && line[*i] == '.')
	{
		++(*i);
		while (line[*i] && line[*i] >= '0' && line[*i] <= '9')
		{
			*float_value += (double)(line[*i] - '0') / j;
			j *= 10;
			++(*i);
		}
	}
}

double	ft_atof(const char *nptr)
{
	double	float_value;
	int		i;
	int		isnegative;
	char	*line;

	i = 0;
	float_value = 0.0;
	isnegative = 1;
	if (nptr)
	{
		line = ft_strtrim(nptr, "\f\n\t\r\v ");
		if (line[i] && line[i] == '-')
		{
			isnegative = -1;
			i++;
		}
		ft_atof_sub(&i, line, &float_value);
		free(line);
		return (float_value * isnegative);
	}
	return (0);
}

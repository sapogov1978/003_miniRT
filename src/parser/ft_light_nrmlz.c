/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_light_nrmlz.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 22:26:05 by brattles          #+#    #+#             */
/*   Updated: 2021/05/10 14:07:10 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_light_nrmlz(t_scn *scn)
{
	double	brightness_summ;
	t_lgts	*temp;

	brightness_summ = scn->amb_brightness;
	temp = scn->lgts;
	while (temp)
	{
		brightness_summ += temp->brightness;
		temp = temp->next;
	}
	if (brightness_summ > 1)
	{
		scn->amb_brightness /= brightness_summ;
		temp = scn->lgts;
		while (temp)
		{
			temp->brightness /= brightness_summ;
			temp = temp->next;
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memclean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 12:36:21 by brattles          #+#    #+#             */
/*   Updated: 2021/05/10 12:48:28 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memclean(void **ptr)
{
	if (ptr != NULL && *ptr != NULL && (char *)*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

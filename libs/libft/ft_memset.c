/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:55:18 by brattles          #+#    #+#             */
/*   Updated: 2021/04/17 19:37:08 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *start, int fill, size_t qty)
{
	unsigned char	*c_start;

	c_start = (unsigned char *)start;
	if (qty == 0)
		return (start);
	while (qty-- > 0)
	{
		*c_start++ = fill;
	}
	return (start);
}

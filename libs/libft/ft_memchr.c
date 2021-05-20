/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:47:14 by brattles          #+#    #+#             */
/*   Updated: 2021/04/17 19:29:12 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*c_s;

	c_s = (unsigned char *)s;
	while (n-- > 0)
	{
		if (*c_s == (unsigned char)c)
			return (c_s);
		c_s++;
	}
	return (NULL);
}

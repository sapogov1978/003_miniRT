/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 00:11:43 by brattles          #+#    #+#             */
/*   Updated: 2021/04/17 20:21:19 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*c_s;

	c_s = (char *)s;
	while (*c_s != c)
	{
		if (*c_s == '\0')
			return (NULL);
		c_s++;
	}
	return (c_s);
}

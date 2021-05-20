/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 01:02:56 by brattles          #+#    #+#             */
/*   Updated: 2021/04/17 20:22:25 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*c_s;

	c_s = (char *)(s + ft_strlen(s));
	while (*c_s != c)
	{
		if (*c_s == '\0' && !c)
			return (c_s);
		if (c_s == s)
			return (NULL);
		c_s--;
	}
	return (c_s);
}

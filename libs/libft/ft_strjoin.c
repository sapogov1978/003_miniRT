/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 01:39:39 by brattles          #+#    #+#             */
/*   Updated: 2021/04/17 19:50:01 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*strjoin;
	int				i;
	int				j;
	int				len[2];

	i = 0;
	j = 0;
	len[0] = ft_strlen(s1);
	len[1] = ft_strlen(s2);
	strjoin = (char *)malloc(sizeof(char) * (len[0] + len[1] + 1));
	if (!strjoin)
		return (NULL);
	while (s1 && i < len[0])
	{
		strjoin[i] = s1[i];
		i++;
	}
	while (s2 && j < len[1])
	{
		strjoin[i] = s2[j];
		i++;
		j++;
	}
	strjoin[len[0] + len[1]] = '\0';
	return (strjoin);
}

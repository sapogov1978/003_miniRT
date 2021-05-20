/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 02:06:34 by brattles          #+#    #+#             */
/*   Updated: 2021/04/17 20:45:42 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_int_len(int n)
{
	int	int_len;

	int_len = 0;
	if (n == 0)
		int_len = 1;
	while (n)
	{
		n = n / 10;
		int_len = int_len + 1;
	}
	return (int_len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		vars[2];

	vars[0] = 0;
	vars[1] = ft_int_len(n);
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		vars[1]++;
	str = (char *)malloc(sizeof(char) * (vars[1] + 1));
	if (!str)
		return (NULL);
	str[vars[1]] = 0;
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
		vars[0]++;
	}
	while (vars[0] < vars[1]--)
	{
		str[vars[1]] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}

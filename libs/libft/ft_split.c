/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 02:52:42 by brattles          #+#    #+#             */
/*   Updated: 2021/05/10 12:47:06 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putmmrback(char **split_table)
{
	int	i;

	i = 0;
	while (split_table[i] != NULL)
	{
		free(split_table[i]);
		i++;
	}
	free(split_table);
	split_table = NULL;
}

static int	ft_line_len(char const *s, int start, char c)
{
	int		line_len;

	line_len = 0;
	while (s[start] && s[start] != c)
	{
		line_len++;
		start++;
	}
	return (line_len);
}

static int	ft_lines_qty(char const *s, char c)
{
	int		lines_qty;
	int		i;
	int		counted_fl;

	counted_fl = 1;
	i = 0;
	lines_qty = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			if (counted_fl == 0)
				lines_qty++;
			counted_fl = 1;
		}
		else
			counted_fl = 0;
		i++;
	}
	if (counted_fl == 0)
		lines_qty++;
	return (lines_qty);
}

char	**ft_split(char const *s, char c)
{
	char	**split_table;
	int		lines_qty;
	int		i[2];

	i[0] = 0;
	i[1] = 0;
	lines_qty = ft_lines_qty(s, c);
	split_table = ft_calloc(lines_qty + 1, (sizeof(char *)));
	if (!split_table)
		return (NULL);
	while (lines_qty--)
	{
		while (s[i[0]] && s[i[0]] == c)
			i[0]++;
		split_table[i[1]] = ft_substr(s, i[0], ft_line_len(s, i[0], c));
		if (!split_table[i[1]])
		{
			ft_putmmrback(split_table);
			return (NULL);
		}
		i[1]++;
		i[0] = i[0] + ft_line_len(s, i[0], c);
	}
	ft_memclean((void *)&split_table[i[1]]);
	return (split_table);
}

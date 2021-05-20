/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 14:33:50 by brattles          #+#    #+#             */
/*   Updated: 2021/04/17 13:26:01 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_print_help(void)
{
	int		fd;
	char	buff;
	int		read_len;
	int		i;

	i = 0;
	read_len = 1;
	fd = open("minirt_help.txt", O_RDONLY);
	if (!fd)
		ft_panic("No MAN page found");
	while (read_len > 0)
	{
		read_len = read(fd, &buff, 1);
		if (!read_len && i == 0)
			ft_panic("Couldn't read from MAN file");
		if (buff != '\0')
			ft_putchar_fd(buff, 1);
		i++;
	}
	close (fd);
}

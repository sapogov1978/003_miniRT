/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_entry_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 02:01:17 by brattles          #+#    #+#             */
/*   Updated: 2021/04/19 00:26:48 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s1 == *s2 && *s2 != '\0')
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

static void	ft_file_ext_check(char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] == '.')
		{
			if (argv[1][i + 1] == 'r' && argv[1][i + 2] == 't'
				&& argv[1][i + 3] == '\0')
				return ;
			else
				ft_panic("Incorrect scene file.\n\
						See miniRT -h or miniRT --help for instructions");
		}
		i++;
	}
	ft_panic("Incorrect scene file.\n\
			See miniRT -h or miniRT --help for instructions");
}

int	ft_entry_check(int argc, char **argv)
{
	int	fd;

	if ((argc == 1) || (argc > 3) \
		|| (argc == 3 && ft_strcmp(argv[2], "--save") != 0))
		ft_panic ("Wrong argument\n\
				See miniRT -h or miniRT --help for instructions");
	if (argc == 2 && (ft_strcmp(argv[1], "-h") == 0 \
		|| ft_strcmp(argv[1], "--help") == 0))
	{
		ft_print_help();
		exit (EXIT_SUCCESS);
	}
	ft_file_ext_check(argv);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_panic("File not found");
	if (read(fd, NULL, 0) < 0)
		ft_panic("Couldn't read from file");
	return (fd);
}

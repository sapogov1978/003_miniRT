/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 22:09:26 by brattles          #+#    #+#             */
/*   Updated: 2021/04/18 17:29:32 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

void	ft_free_struct(t_fd_lst *fd_lst)
{
	free(fd_lst);
	fd_lst = NULL;
}

void	ft_free_buff(char *buff)
{
	free(buff);
	buff = NULL;
}

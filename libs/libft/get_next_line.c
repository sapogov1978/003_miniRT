/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:34:14 by brattles          #+#    #+#             */
/*   Updated: 2021/04/18 17:29:53 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <stdio.h> //

t_fd_lst	*ft_lstadd(int fd)
{
	t_fd_lst	*fd_lst;

	fd_lst = malloc(sizeof(t_fd_lst));
	if (!fd_lst)
		return (NULL);
	fd_lst->fd = fd;
	fd_lst->leftover = NULL;
	fd_lst->next = NULL;
	return (fd_lst);
}

int	ft_makeline_saverest(char **leftover, char **line)
{
	char	*new_leftover;
	int		symb_qty;

	symb_qty = 0;
	if (!*leftover)
		return (0);
	while ((*leftover)[symb_qty] != '\n' && (*leftover)[symb_qty] != '\0')
		symb_qty++;
	if ((*leftover)[symb_qty] == '\n')
	{
		*line = (char *)malloc((symb_qty + 1));
		if (!*line)
			return (-1);
		*line = ft_strncpy(*line, *leftover, symb_qty);
		new_leftover = ft_substr(*leftover, symb_qty + 1, \
						(ft_strlen(*leftover) - symb_qty - 1));
		free(*leftover);
		*leftover = NULL;
		*leftover = new_leftover;
		return (1);
	}
	return (0);
}

int	ft_itt_check(int read_len, char **leftover, char **line, char *buff)
{
	char	*tmp;

	if (read_len == 0)
	{
		*line = ft_strjoin(*leftover, "");
		if (!*line)
			return (-1);
		free(*leftover);
		*leftover = NULL;
	}
	if (!(*leftover) && read_len > 0)
	{
		*leftover = ft_strjoin(buff, "");
		if (!*leftover)
			return (-1);
	}
	else if (read_len > 0)
	{
		tmp = *leftover;
		*leftover = ft_strjoin(tmp, buff);
		if (!*leftover)
			return (-1);
		ft_free_buff(tmp);
	}
	return (0);
}

int	ft_get_line(int *fd, char **leftover, char **line)
{
	char	*buff;
	int		i;
	int		read_len;

	read_len = 1;
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (-1);
	while (read_len > 0)
	{
		i = ft_makeline_saverest(&(*leftover), line);
		if ((*leftover) && i > 0)
		{
			ft_free_buff(buff);
			return (i);
		}
		read_len = read(*fd, buff, BUFFER_SIZE);
		if (read_len < 0)
			return (-1);
		buff[read_len] = '\0';
		ft_itt_check(read_len, &(*leftover), line, buff);
	}
	ft_free_buff(buff);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static t_fd_lst	*fd_lst;
	t_fd_lst		*fd_tmp;
	int				result;

	if (fd < 0 || BUFFER_SIZE < 1 || !line || read(fd, NULL, 0) < 0)
		return (-1);
	if (!fd_lst)
		fd_lst = ft_lstadd(fd);
	fd_tmp = fd_lst;
	while (fd_tmp && fd_tmp->fd != fd)
	{
		if (!fd_tmp->next)
			fd_tmp->next = ft_lstadd(fd);
		fd_tmp = fd_tmp->next;
	}
	result = ft_get_line(&fd_tmp->fd, &fd_tmp->leftover, line);
	if (result == 0)
		ft_free_struct(fd_lst);
	return (result);
}

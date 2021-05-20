/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:36:00 by brattles          #+#    #+#             */
/*   Updated: 2021/04/17 22:21:16 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

typedef struct s_fd_lst	t_fd_lst;

struct				s_fd_lst
{
	int				fd;
	char			*leftover;
	struct s_fd_lst	*next;
};

void				ft_free_struct(t_fd_lst *fd_lst);
void				ft_free_buff(char *buff);
t_fd_lst			*ft_lstadd(int fd);
size_t				ft_strlen(const char *s);
char				*ft_strncpy(char *dst, const char *src, size_t dstsize);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_makeline_saverest(char **leftover, char **line);
int					ft_itt_check(int read_len, char **leftover,
						char **line, char *buff);
int					ft_get_line(int *fd, char **leftover, char **line);
int					get_next_line(int fd, char **line);

#endif

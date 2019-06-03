/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:34:17 by rsticks           #+#    #+#             */
/*   Updated: 2019/06/03 15:34:42 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

void				ft_join(char ***line, char **buf, char **temp)
{
	*temp = **line;
	**line = ft_strjoin(**line, *buf);
	free(*temp);
}

int					get_next_line(const int fd, char **line)
{
	struct s_gnl	a;
	static char		*ost_tab[10241];

	if (fd < 0 || fd > 10240 || !line)
		return (-1);
	a.buf = ft_strnew(BUFF_SIZE);
	*line = ft_strnew(0);
	if (ost_tab[fd] != NULL)
	{
		a.buf = ft_strcpy(a.buf, ost_tab[fd]);
		ft_strdel(&ost_tab[fd]);
	}
	a.if_n = 0;
	while (a.if_n == 0)
	{
		a.x = 0;
		while ((a.buf[a.x] != '\0') && (a.buf[a.x] != '\n'))
			a.x++;
		if (a.buf[a.x] == '\n')
		{
			a.buf2 = ft_strnew(a.x);
			a.buf2 = ft_strncpy(a.buf2, a.buf, a.x);
			ft_join(&line, &a.buf2, &a.temp);
			a.if_n = 1;
			a.temp = ft_strchr(a.buf, '\n');
			ost_tab[fd] = ft_strnew(ft_strlen(++a.temp));
			ost_tab[fd] = ft_strcpy(ost_tab[fd], a.temp);
			ft_strdel(&a.buf2);
			ft_strdel(&a.buf);
		}
		else if (a.buf[a.x] == '\0')
		{
			ft_join(&line, &a.buf, &a.temp);
			ft_bzero(a.buf, BUFF_SIZE + 1);
			a.i = read(fd, a.buf, BUFF_SIZE);
			if (a.i <= 0)
			{
				ft_strdel(&a.buf);
				if (*line && **line != '\0')
					return (1);
				else
					return (a.i);
			}
		}
	}
	return (1);
}

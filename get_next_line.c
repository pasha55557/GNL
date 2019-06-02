/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:34:17 by rsticks           #+#    #+#             */
/*   Updated: 2019/06/02 19:12:58 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int				get_next_line(const int fd, char **line)
{
	struct 		s_gnl a;
	char		*buf;
	char		*buf2;
	static char	*ost_tab[10241];
	char		*temp;

	a.if_n = 0;
	if (fd < 0 || fd > 10240 || !line)
		return (-1);
	buf = ft_strnew(BUFF_SIZE);
	//if (*line == NULL)
	//	*line = (char*)malloc(sizeof(char));
	if (*line != NULL)
		ft_bzero(*line, (ft_strlen(*line)));
	if (ost_tab[fd] != NULL)
	{
		buf = ft_strcpy(buf, ost_tab[fd]);
		ft_strdel(&ost_tab[fd]);
	}
	while (a.if_n == 0)
	{
		a.x = 0;
		while ((buf[a.x] != '\0') && (buf[a.x] != '\n'))
			a.x++;
		if (buf[a.x] == '\n')
		{
			buf2 = ft_strnew(a.x);
			buf2 = ft_strncpy(buf2, buf, a.x);
			temp = *line;
			*line = ft_strjoin(*line, buf2);
			free(temp);
			a.if_n = 1;
			temp = ft_strchr(buf, '\n');
			ost_tab[fd] = ft_strnew(ft_strlen(++temp));
			ost_tab[fd] = ft_strcpy(ost_tab[fd], temp);
			ft_strdel(&buf2);
			ft_strdel(&buf);
		}
		else if (buf[a.x] == '\0')
		{
			temp = *line;
			*line = ft_strjoin(*line, buf);
			free(temp);
			ft_bzero(buf, BUFF_SIZE + 1);
			a.i = read(fd, buf, BUFF_SIZE);
			if (a.i <= 0)
			{
				ft_strdel(&buf);
				if (*line && **line != '\0')
					return (1);
				else
				{
					ft_strdel(line); 
					return (a.i);
				}
			}
		}
	}
	return (1);
}

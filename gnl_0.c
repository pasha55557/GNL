/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_0.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:34:17 by rsticks           #+#    #+#             */
/*   Updated: 2019/06/02 16:52:35 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
    char		*buf[2];
	static char	*ost_tab[10240];
    int			i;
	int			x;
	int			if_n;
	char		*temp;

// ПРОВЕРОЧКИ
	x = 0;
	if_n = 0;
	if (fd < 0 || fd > 10240 || !line)
		return (-1);
	buf[0] = ft_strnew(BUFF_SIZE); // ВЫДЕЛИЛИ ПАМЯТЬ ПОД БУФЕР

	*line = (char*)malloc(sizeof(char));
		**line = '\0';
	
	if (ost_tab[fd] == NULL) // ЕСЛИ НЕТ ОСТАТКА
	{
		i = read(fd, buf[0], BUFF_SIZE);
		if (i <= 0) 
		{
			ft_strdel(line);
			return (i);
		}
	}
	else // ЕСЛИ ЕСТЬ ОСТАТОК, ЗАПИСЫВАЕМ ЕГО В БУФЕР
	{
		buf[0] = ft_strcpy(buf[0], ost_tab[fd]);
		ft_strdel(&ost_tab[fd]);
	}
	
	
// ОСНОВА
	while (if_n == 0) // УЖЕ БЫЛ '\n' В ПРЕДИДУЩЕМ ЦИКЛЕ?
	{
		x = 0;
		while ((buf[0][x] != '\0') && (buf[0][x] != '\n')) // идем до конца строки или конца всего
			x++;
		if (buf[0][x] == '\n') // ECЛИ ВСТРЕТИЛИ '\n'
		{
			buf[1] = ft_strnew(x);
			buf[1] = ft_strncpy(buf[1], buf[0], x);
			temp = ft_strjoin(*line, buf[1]);
			free(*line);
			*line = temp;
			if_n = 1;
			buf[0] = ft_strchr(buf[0], '\n');
			ost_tab[fd] = ft_strnew(ft_strlen(++buf[0]));
			ost_tab[fd] = ft_strcpy(ost_tab[fd], buf[0]);
			ft_strdel(&buf[1]);
		}
		else if (buf[0][x] == '\0')  // ЕСЛИ ВСТРЕТИЛИ '\0'
		{
			temp = *line;
			*line = ft_strjoin(*line, buf[0]);
			free(temp);
			ft_bzero(buf[0], BUFF_SIZE + 1);
			i = read(fd, buf[0], BUFF_SIZE);
			if (i <= 0)
			{
				ft_strdel(&buf[0]);
				if (*line && **line != '\0')
				return (1);
				else
				{
				ft_strdel(line);
				return (i);	
				}
				
			}	
		}
	}
// КОНЦОВКА
//ft_strdel(&buf[0]);
	return (1);	
}
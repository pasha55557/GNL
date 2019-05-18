/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:34:17 by rsticks           #+#    #+#             */
/*   Updated: 2019/05/18 17:32:10 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
    char		*buf;
	char		*buf2;
	static char	*ost_tab[10240];
    int			i;
	int			x;
	int			if_n;

// ПРОВЕРОЧКИ
	x = 0;
	if_n = 0;
	if (fd < 0 || fd > 10240)
		return (-1);
	buf = ft_strnew(BUFF_SIZE + 1); // ВЫДЕЛИЛИ ПАМЯТЬ ПОД БУФЕР

    if (*line == NULL)
	{
		*line = (char*)malloc(sizeof(char)); // ВЫДЕЛИЛИ ПАМЯТЬ ПОД ЛИНИЮ
		**line = '\0';
	}
	else
	{
		ft_strdel(line);
		*line = (char*)malloc(sizeof(char));
		**line = '\0';
	}
	
	if (ost_tab[fd] == NULL) // ЕСЛИ НЕТ ОСТАТКА
	{
		i = read(fd, buf, BUFF_SIZE);
		if (i <= 0) 
		{
			ft_strdel(line);
			return (i);
		}
		buf[i] = '\0';
	}
	else // ЕСЛИ ЕСТЬ ОСТАТОК, ЗАПИСЫВАЕМ ЕГО В БУФЕР
	{
		buf = ft_strcpy(buf, ost_tab[fd]);
		ft_strdel(&ost_tab[fd]);
	}
	
	
// ОСНОВА
	while (if_n == 0) // УЖЕ БЫЛ '\n' В ПРЕДИДУЩЕМ ЦИКЛЕ?
	{
		x = 0;
		while ((buf[x] != '\0') && (buf[x] != '\n')) // идем до конца строки или конца всего
			x++;
		if (buf[x] == '\n') // ECЛИ ВСТРЕТИЛИ '\n'
		{
			buf2 = ft_strnew(x);
			buf2 = ft_strncpy(buf2, buf, x);
			*line = ft_strjoin(*line, buf2);
			if_n = 1;
			buf = ft_strchr(buf, '\n');
			ost_tab[fd] = ft_strnew(ft_strlen(++buf));
			ost_tab[fd] = ft_strcpy(ost_tab[fd], buf);
			ft_strdel(&buf2);
		}
		else if (buf[x] == '\0')  // ЕСЛИ ВСТРЕТИЛИ '\0'
		{
			*line = ft_strjoin(*line, buf);
			ft_bzero(buf, BUFF_SIZE + 1);
			i = read(fd, buf, BUFF_SIZE);
			if (i <= 0)
			{
				if (*line && **line != '\0')
				return(1);
				return (i);
			}	
		}
	}

// КОНЦОВКА
	//ft_strdel(&buf);
	return (i);	
}
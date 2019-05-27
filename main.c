/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 12:36:14 by rsticks           #+#    #+#             */
/*   Updated: 2019/05/27 16:54:20 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int		get_next_line(const int fd, char **line);

int main(int argc, char **argv)
{
    int fd;
    char *line;
	int i;

i = 0;
	if (argc < 2)
		return(0);
	
    fd = open(argv[1], O_RDONLY);
    while (get_next_line(fd, &line) == 1)
	{
		printf("%s\n", line);
		i++;
	}
		printf("КОЛВО ЦИКЛОВ =%d", i);
    return (0);
}
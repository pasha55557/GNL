/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 12:36:14 by rsticks           #+#    #+#             */
/*   Updated: 2019/06/02 16:42:22 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft/libft.h"

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
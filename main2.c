/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 15:00:54 by rsticks           #+#    #+#             */
/*   Updated: 2019/05/18 17:07:41 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int		get_next_line(const int fd, char **line);
/*
**  1 line with 8 chars with Line Feed
*/

int				main(void)
{
	char		*line;
	int			fd[3];
	int			ret;
	int			count_lines;
	char		*filename;
	//char		*filename2;
	int			errors;

	filename = "test.txt";
	//filename2 = "test2.txt";
	fd[1] = open(filename, O_RDONLY);
//	fd[2] = open(filename2, O_RDONLY);
	if (fd[1] > 2)
	{
		count_lines = 0;
		errors = 0;
		line = NULL;
		while ((ret = get_next_line(fd[1], &line)) > 0)
		{
			if (count_lines == 0 && strcmp(line, "1234567") != 0)
				errors++;
				printf("%s\n", line);
				//ret = get_next_line(fd[2], &line);
				//printf("%s\n", line);
			count_lines++;
			if (count_lines > 50)
				break;
		}
		close(fd[1]);
		//close(fd[2]);
		if (count_lines != 1)
			printf("-> must have returned '1' once instead of %d time(s)\n", count_lines);
		if (errors > 0)
			printf("-> must have read \"1234567\" instead of \"%s\"\n", line);
		if (count_lines == 1 && errors == 0)
			printf("OK\n");
	}
	else
		printf("An error occured while opening file %s\n", filename);
	return (0);
}

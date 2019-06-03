/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:38:16 by rsticks           #+#    #+#             */
/*   Updated: 2019/06/03 15:30:38 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include "libft/libft.h"

# define BUFF_SIZE 20

struct			s_gnl
{
	char		*buf;
	char		*buf2;
	char		*temp;
	int			i;
	int			x;
	int			if_n;
};

int				get_next_line(const int fd, char **line);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:38:16 by rsticks           #+#    #+#             */
/*   Updated: 2019/05/18 16:12:35 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
//# include "get_next_line.h"
# include "libft/libft.h"
# define BUFF_SIZE 10

int		get_next_line(const int fd, char **line);

#endif
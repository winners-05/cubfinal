/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:02:23 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/01/30 15:14:12 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H


 # define BUFFER_SIZE 10000
# include <fcntl.h>

# include <stdlib.h>

# include <unistd.h>
#include "../cub3d.h"

int				outtil(int fd, char **rest, char **line);
int				get_next_line(int fd, char **line);
char			*kayn_ster(char		*str);


#endif

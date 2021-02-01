/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 14:43:43 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/01/31 16:59:37 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void error_gestion(int i)
{
	if (i == 1)
		ft_putstr("ERROR \n check file EXTENSION");
	if (i == 2)
		ft_putstr("ERROR \n ARGUMENT MUST BE SAVE");
	if (i == 3)
		ft_putstr("ERROR \n WRONG FILE CONFIGURATION");
    if(i == 4)
        ft_putstr("ERROR \n WRONG NUMBER OF PARAMETERS");
	if (i == 5)
		ft_putstr("ERROR \n some of parameters are wrong");
	if(i == 6)
		ft_putstr("ERROR \n Wrong number of parameters");
	if (i == 7)
		ft_putstr("ERROR \n Double inclusion");
	if (i == 8)
		ft_putstr("ERROR \n Wrong colors");
	if (i == 9)
		ft_putstr("ERROR \n check your FILE");
	exit(0);
}
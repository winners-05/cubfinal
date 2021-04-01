/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 14:43:43 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/02/09 18:35:38 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		test_ext(char *str)
{
	int		i;
	int		j;

	i = ft_strlen(str);
	j = ft_strlen(str) - 1;
	if (str[j] == 'b' && str[j - 1] == 'u' && str[j - 2] == 'c'
	&& str[j - 3] == '.' && str[j - 4] == '/')
		error_gestion(1);
}

int			has_sp(float x, float y)
{
	int		x1;
	int		y1;

	if (x < 0 || x > (g_mwidth * TILE_SIZE) ||
		y < 0 || y > (g_mheight * TILE_SIZE))
		return (1);
	x1 = floor(x / TILE_SIZE);
	y1 = floor(y / TILE_SIZE);
	if (g_allmap_with_spaces[y1][x1] == '2')
		return (1);
	else
		return (0);
}

void		error_gestion(int i)
{
	if (i == 1)
		ft_putstr("ERROR \n check file EXTENSION");
	if (i == 2)
		ft_putstr("ERROR \n ARGUMENT MUST BE 'save'");
	if (i == 3)
		ft_putstr("ERROR \n WRONG FILE CONFIGURATION");
	if (i == 4)
		ft_putstr("ERROR \n WRONG NUMBER OF PARAMETERS");
	if (i == 5)
		ft_putstr("ERROR \n some of parameters are wrong");
	if (i == 6)
		ft_putstr("ERROR \n Wrong number of parameters");
	if (i == 7)
		ft_putstr("ERROR \n Double inclusion");
	if (i == 8)
		ft_putstr("ERROR \n Wrong colors");
	if (i == 9)
		ft_putstr("ERROR \n check your FILE");
	if (i == 10)
		ft_putstr("ERROR \n Colors ERROR");
	if (i == 11)
		ft_putstr("ERROR \n FILE NOT FOUND");
	if (i == 12)
		ft_putstr("ERROR \n NEW LINE");
	exit(0);
}

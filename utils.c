/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 11:51:15 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/02/25 15:55:20 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		read_map_line(char *str)
{
	if (str[0] != '\0' && !g_map_st)
		g_map_st = 1;
	if (g_map_st && (str[0] != '\0'))
		g_map = ft_strjoin_line(g_map, str);
	if (g_map_st && str[0] == '\0')
		error_gestion(12);
}

void		check_map_arrays(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '\0')
	{
		ft_putstr("ERROR \n map doesnt exist");
		exit(0);
	}
	while (str[i] != '\0')
	{
		if ((str[i] != '1' && str[i] != '0' &&
			str[i] != ' ' && str[i] != '2' &&
			str[i] != 'N' && str[i] != 'S' && str[i] != 'E' && str[i] != 'W')
			&& str[i] != '\n')
		{
			ft_putstr("ERROR \n Check your MAP");
			exit(0);
		}
		i++;
	}
}

void		split_map(void)
{
	g_allmap = ft_split(g_map, '\n');
}

void		fill_map(char **str)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = 1;
	j = 1;
	x = 0;
	y = 0;
	while (x < g_mheight)
	{
		while (y < g_mwidth)
		{
			if (y < ft_strlen(g_allmap[x]))
				str[i][j] = g_allmap[x][y];
			
			y++;
			j++;
		}
		i++;
		x++;
		j = 1;
		y = 0;
	}
}

void		check_arrays(void)
{
	int		i;
	int		j;
	int		x;

	i = 0;
	j = 0;
	x = 0;
	while (g_allmap[i])
	{
		while (g_allmap[i][j] != '\0')
			j++;
		i++;
		if (j > x)
			x = j;
		j = 0;
	}
	g_mwidth = x;
}

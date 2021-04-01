/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 11:34:02 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/02/09 15:51:52 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			numbers_of_parameters(char *str, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			i++;
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i] != c && str[i] != '\0')
			j++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (j);
}

void		check_player(char **str)
{
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'N' || str[i][j] == 'E' || str[i][j] == 'S'
				|| str[i][j] == 'W')
				init_player(str[i][j], j, i);
			j++;
		}
		i++;
	}
}

void		init_player(char x, int i, int j)
{
	if (g_p)
	{
		ft_putstr("ERROR \nmore than one g_pl");
		exit(0);
	}
	else
	{
		g_pl.x = (i * TILE_SIZE) + (TILE_SIZE / 2);
		g_pl.y = (j * TILE_SIZE) + (TILE_SIZE / 2);
		g_p = 1;
		if (x == 'N')
			g_pl.rtang = 270 * (M_PI / 180);
		else if (x == 'S')
			g_pl.rtang = 90 * (M_PI / 180);
		else if (x == 'E')
			g_pl.rtang = 0;
		else if (x == 'W')
			g_pl.rtang = M_PI;
		g_pl.fov = 60 * (M_PI / 180);
		g_pl.tdirec = 0;
		g_pl.wdirec = 0;
		g_pl.mspeed = 10;
		g_pl.rspeed = 4 * (M_PI / 180);
	}
}

void		check_play_exist(void)
{
	if (g_pl.x == -1 || g_pl.y == -1)
	{
		ft_putstr("ERROR \ng_pl not FOUND");
		exit(0);
	}
}

void		fill_g_allmap(void)
{
	char	**str;
	int		i;

	i = 0;
	str = (char **)malloc((g_mheight + 3) * sizeof(char*));
	while (i < g_mheight + 2)
	{
		str[i] = (char *)malloc((g_mwidth + 3) * sizeof(char));
		i++;
	}
	str[i] = NULL;
	fill_spaces(str);
	fill_map(str);
	check_close(str);
	fill_map_with_one(str);
	check_player(str);
	check_play_exist();
	g_allmap_with_spaces = str;
	free_memory(g_allmap);
}

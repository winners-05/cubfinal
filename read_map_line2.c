/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 11:51:42 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/02/09 12:30:02 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		check_width(void)
{
	int		i;

	i = 0;
	while (g_allmap[i])
		i++;
	g_mheight = i;
}

void		fill_spaces(char **str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (j < g_mwidth + 2)
			j++;
		str[i][j] = '\0';
		i++;
		j = 0;
	}
	i = 0;
	j = 0;
	while (i < g_mheight + 2)
	{
		j = 0;
		while (j < g_mwidth + 2)
		{
			str[i][j] = ' ';
			j++;
		}
		i++;
	}
}

int			check(int i, char c)
{
	if (i == 0)
	{
		if (c != 1 && c != '0' && c != 2 && c != 'N' && c != 'W' &&
			c != 'E' && c != 'S' && c != 'S' && c != ' ')
			return (1);
		return (0);
	}
	return (0);
}

void		check_close(char **str)
{
	int		i;
	int		j;

	i = 0;
	g_co = 0;
	while (i <= g_mheight)
	{
		j = 0;
		while (j <= g_mwidth)
		{
			g_co += str[i][j] == '2';
			if (str[i][j] != ' ' && str[i][j] != '1')
			{
				if ((str[i - 1][j] == ' ') || (str[i + 1][j] == ' ') ||
					(str[i][j - 1] == ' ') || (str[i][j + 1] == ' '))
				{
					ft_putstr("ERROR\n map isnt closed :)");
					exit(0);
				}
			}
			j++;
		}
		i++;
	}
}

void		fill_map_with_one(char **str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == ' ')
				str[i][j] = '1';
			j++;
		}
		i++;
	}
}

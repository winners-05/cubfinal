/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 14:31:08 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/02/09 15:52:15 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		treat_no(char *line)
{
	int		num;
	char	**split;
	char	*str;

	str = ft_strdup("");
	if (g_no != NULL)
	{
		ft_putstr("ERROR \n Double Inclusion");
		exit(0);
	}
	split = ft_split(line, ' ');
	num = numbers_of_parameters(line, ' ');
	if (num != 2)
	{
		ft_putstr("ERROR :\n Bad syntax in NO");
		exit(0);
	}
	check_ext(&split[1][0], 'N');
	free_all(str, split);
}

void		treat_south(char *line)
{
	int		num;
	char	**split;
	char	*str;

	str = ft_strdup("");
	split = ft_split(line, ' ');
	num = numbers_of_parameters(line, ' ');
	if (num != 2)
	{
		ft_putstr("Error :\n Bad syntax in st");
		exit(0);
	}
	if (g_so != NULL)
	{
		ft_putstr("ERROR \n Double inclusion");
		exit(0);
	}
	check_ext(&split[1][0], '2');
	free_all(str, split);
}

void		treat_east(char *line)
{
	int		num;
	char	**split;
	char	*str;

	str = ft_strdup("");
	split = ft_split(line, ' ');
	num = numbers_of_parameters(line, ' ');
	if (g_ea != NULL)
	{
		ft_putstr("ERROR \n Double inclusion");
		exit(0);
	}
	if (num != 2)
	{
		ft_putstr("Error :\n Bad syntax in EAST");
		exit(0);
	}
	check_ext(&split[1][0], 'E');
	free_all(str, split);
}

void		treat_west(char *line)
{
	int		num;
	char	**split;
	char	*str;

	str = ft_strdup("");
	split = ft_split(line, ' ');
	num = numbers_of_parameters(line, ' ');
	if (g_we != NULL)
	{
		ft_putstr("ERROR \n Double inclusion");
		exit(0);
	}
	if (num != 2)
	{
		ft_putstr("Error :\n Bad syntax in WEST");
		exit(0);
	}
	check_ext(&split[1][0], 'W');
	free_all(str, split);
}

void		treat_sprite(char *line)
{
	int		num;
	char	**split;
	char	*str;

	str = ft_strdup("");
	split = ft_split(line, ' ');
	num = numbers_of_parameters(line, ' ');
	if (g_spr != NULL)
	{
		ft_putstr("ERROR \n Double inclusion");
		exit(0);
	}
	if (num != 2)
	{
		ft_putstr("Error :\n Bad syntax in Sprite");
		exit(0);
	}
	check_ext(&split[1][0], 'S');
	free_all(str, split);
}

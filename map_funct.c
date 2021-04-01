/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_funct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:19:42 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/02/04 19:22:55 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		free_all(char *str, char **s)
{
	free(str);
	free_memory(s);
}

void		map_funct(char *line)
{
	if (line[0] == 'R' && line[1] == ' ')
		treat_resolution(line);
	else if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		treat_no(line);
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		treat_south(line);
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		treat_east(line);
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		treat_west(line);
	else if (line[0] == 'C' && line[1] == ' ')
		treat_c(line);
	else if (line[0] == 'F' && line[1] == ' ')
		treat_f(line);
	else if (line[0] == 'S' && line[1] == ' ')
		treat_sprite(line);
	else if (params())
		read_map_line(line);
	else
		error_gestion(5);
}

void		treat_resolution(char *line)
{
	int		num;
	char	**split;

	num = numbers_of_parameters(line, ' ');
	if (num != 3)
		error_gestion(6);
	if (g_height != 0 && g_width != 0)
		error_gestion(7);
	split = ft_split(line, ' ');
	if (is_digit(&split[1][0]) && is_digit(&split[2][0]))
		re(ft_atoi(&split[1][0]), ft_atoi(&split[2][0]));
	else
	{
		ft_putstr("Error :\nwrong resolution");
		exit(0);
	}
	free_memory(split);
}

void		treat_c(char *line)
{
	int		num;
	char	**split;
	char	**sp;

	num = 0;
	split = ft_split(line, ' ');
	sp = ft_split(&split[1][0], ',');
	treat_virgul(split[1]);
	num = numbers_of_parameters(&split[1][0], ',');
	if (g_cr != -1 && g_cg != -1 && g_cb != -1)
		error_gestion(7);
	if (num != 3)
		error_gestion(6);
	if (is_digit(&sp[0][0]) && is_digit(&sp[1][0]) && is_digit(&sp[2][0]))
		get_c(ft_atoi(&sp[0][0]), ft_atoi(&sp[1][0]), ft_atoi(&sp[2][0]));
	else
		error_gestion(8);
	free_memory(split);
	free_memory(sp);
}

void		treat_f(char *line)
{
	int		num;
	char	**split;
	char	**sp;

	split = ft_split(line, ' ');
	sp = ft_split(&split[1][0], ',');
	treat_virgul(split[1]);
	num = numbers_of_parameters(&split[1][0], ',');
	if (g_fr != -1 && g_fg != -1 && g_fb != -1)
		error_gestion(7);
	if (num != 3)
		error_gestion(6);
	if (is_digit(&sp[0][0]) && is_digit(&sp[1][0]) && is_digit(&sp[2][0]))
		get_f(ft_atoi(&sp[0][0]), ft_atoi(&sp[1][0]), ft_atoi(&sp[2][0]));
	else
		error_gestion(8);
	free_memory(sp);
	free_memory(split);
}

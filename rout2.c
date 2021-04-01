/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rout2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 16:46:45 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/02/25 15:56:02 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			get_c(int r, int g, int b)
{
	if (r > 255 || g > 255 || b > 255)
		error_gestion(10);
	if (r < 0 || g < 0 || b < 0)
		error_gestion(10);
	else
	{
		g_cr = r;
		g_cg = g;
		g_cb = b;
	}
	return (1);
}

int			get_f(int r, int g, int b)
{
	if (r > 255 || g > 255 || b > 255)
	{
		ft_putstr("ERROR : \n Color of floor  > 255");
		exit(0);
	}
	if (r < 0 || g < 0 || b < 0)
	{
		ft_putstr("ERROR :\n Color of floor < 0");
		exit(0);
	}
	else
	{
		g_fr = r;
		g_fg = g;
		g_fb = b;
	}
	return (1);
}

void		check_ext(char *str, char x)
{
	int		i;
	char	**split;

	split = ft_split(str, '.');
	if ((i = open(str, O_RDONLY) > 0) && x == 'N')
		g_no = ft_strdup(str);
	else if ((i = open(str, O_RDONLY) <= 0) && x == 'N')
		error_gestion(11);
	else if ((i = open(str, O_RDONLY) > 0) && x == '2')
		g_so = ft_strdup(str);
	else if ((i = open(str, O_RDONLY) <= 0) && x == '2')
		error_gestion(11);
	else if ((i = open(str, O_RDONLY) > 0) && x == 'E')
		g_ea = ft_strdup(str);
	else if ((i = open(str, O_RDONLY) <= 0) && x == 'E')
		error_gestion(11);
	else if ((i = open(str, O_RDONLY) > 0) && x == 'W')
		g_we = ft_strdup(str);
	else if ((i = open(str, O_RDONLY) <= 0) && x == 'W')
		error_gestion(11);
	else if ((i = open(str, O_RDONLY) > 0) && x == 'S')
		g_spr = ft_strdup(str);
	else if ((i = open(str, O_RDONLY) <= 0) && x == 'S')
		error_gestion(11);
	free_memory(split);
}

char		*ft_strjoin_line(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s2)
		return (s1);
	if (!s1)
		return (s2);
	str = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	i = -1;
	while (s1[++i])
	{
		str[i] = s1[i];
	}
	j = -1;
	while (s2[++j])
	{
		str[i] = s2[j];
		i++;
	}
	str[i] = '\n';
	str[i + 1] = '\0';
	free(s1);
	return (str);
}


void		check_ceiling(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ',')
			j++;
		i++;
	}
	if (j != 2)
	{
		ft_putstr("ERROR\n Check ceiling/Floor Syntaxe");
		exit(0);
	}
}

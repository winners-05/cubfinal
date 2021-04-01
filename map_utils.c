/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 14:53:30 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/02/05 10:59:52 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_write(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_write(str[i]);
		i++;
	}
}

void		init_param(void)
{
	g_height = 0;
	g_width = 0;
	g_ea = NULL;
	g_no = NULL;
	g_so = NULL;
	g_we = NULL;
	g_fr = -1;
	g_fg = -1;
	g_fb = -1;
	g_cr = -1;
	g_cg = -1;
	g_cb = -1;
	g_spr = NULL;
	g_mwidth = 0;
	g_mheight = 0;
	g_map_st = 0;
	g_map = ft_strdup("");
}

char		**free_memory(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

int			params(void)
{
	if (g_height != 0 && g_width != 0 && g_we != NULL
		&& g_so != NULL && g_ea != NULL && g_no != NULL
		&& g_fr != -1 && g_fg != -1 && g_fb != -1
		&& g_cr != -1 && g_cb != -1 && g_cg != -1)
		return (1);
	return (0);
}

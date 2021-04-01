/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 15:17:37 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/02/05 11:15:57 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float		degree(float x)
{
	return ((180 / M_PI) * x);
}

void		init_sprite(void)
{
	int		i;
	int		j;
	int		k;
	int		w;
	int		h;

	k = 0;
	i = -1;
	g_spri = malloc(sizeof(t_sprite) * (g_co + 1));
	if (!(g_spi.img = mlx_xpm_file_to_image(g_vars.mlx, g_spr, &w, &h)))
		error_gestion(11);
	g_spi.ad = mlx_get_data_addr(g_spi.img, &g_spi.bpp, &g_spi.ln, &g_spi.en);
	while (g_allmap_with_spaces[++i] && (j = -1) && (k < g_co))
	{
		while (g_allmap_with_spaces[i][++j] && (k < g_co))
			if (g_allmap_with_spaces[i][j] == '2')
			{
				g_spri[k].x = (float)((j + 0.5) * 64);
				g_spri[k].y = (float)((i + 0.5) * 64);
				g_spri[k].dist = sqrtf(((g_spri[k].x) - g_pl.x) * ((g_spri[k].x)
				- g_pl.x) + ((g_spri[k].y) - g_pl.y) *
				((g_spri[k].y) - g_pl.y));
				k++;
			}
	}
}

void		sort(void)
{
	int			i;
	int			j;
	t_sprite	tmp;

	i = 0;
	while (i < g_co - 1)
	{
		j = i;
		while (j < g_co - 1)
		{
			if (g_spri[j].dist < g_spri[j + 1].dist)
			{
				tmp = g_spri[j];
				g_spri[j] = g_spri[j + 1];
				g_spri[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void		sprite(void)
{
	float	angle;
	int		k;

	k = -1;
	sort();
	angle = 0;
	while (++k < g_co)
	{
		g_spri[k].dist = sqrtf(((g_spri[k].x) - g_pl.x) * ((g_spri[k].x)
		- g_pl.x) + ((g_spri[k].y) - g_pl.y) * ((g_spri[k].y) - g_pl.y));
		angle = atan2f(g_spri[k].y - g_pl.y, g_spri[k].x - g_pl.x);
		while (angle - g_pl.rtang > M_PI)
			angle -= 2 * M_PI;
		while (angle - g_pl.rtang < -M_PI)
			angle += 2 * M_PI;
		g_spri[k].size = (float)(((int)g_width / g_spri[k].dist) * 64);
		g_spri[k].yof = (float)((int)g_height / 2 - g_spri[k].size / 2);
		g_spri[k].xof = (float)(((degree(angle)
		- degree(g_pl.rtang)) * (int)g_width)
		/ 64 + (((int)g_width / 2) - (int)g_spri[k].size / 2));
		draw_sprite(k);
	}
}

void		draw_sprite(int id)
{
	int		i;
	int		j;
	int		c;
	int		*tmp;
	float	size;

	i = -1;
	size = g_spri[id].size;
	tmp = (int *)g_spi.ad;
	while (++i < size - 1 && (j = -1))
	{
		if (g_spri[id].xof + i <= 0 || g_spri[id].xof + i > (int)g_width - 1)
			continue;
		if (g_rays[(int)(g_spri[id].xof + i)].distance <= g_spri[id].dist)
			continue;
		while (++j < size - 1)
		{
			if (g_spri[id].yof + j <= 0 || g_spri[id].yof + j > g_height - 1)
				continue;
			c = tmp[(int)((64) *
				(64 * j / (int)size) + (64 * i / (int)size))];
			if (c != tmp[0])
				put(&g_img, i + g_spri[id].xof, j + g_spri[id].yof, c);
		}
	}
}

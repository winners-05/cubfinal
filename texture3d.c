/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 16:50:50 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/02/05 10:52:33 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			quit(void)
{
	key_press(53);
	return (0);
}

void		texture(void)
{
	int		i;
	int		j;

	if (!(g_n.img))
		if (!(g_n.img = mlx_xpm_file_to_image(g_vars.mlx, g_no, &i, &j)))
			error_gestion(9);
	if (!(g_n.ad))
		g_n.ad = mlx_get_data_addr(g_n.img, &g_n.bpp, &g_n.ln, &g_n.en);
	if (!(g_st.img))
		if (!(g_st.img = mlx_xpm_file_to_image(g_vars.mlx, g_so, &i, &j)))
			error_gestion(9);
	if (!(g_st.ad))
		g_st.ad = mlx_get_data_addr(g_st.img, &g_st.bpp, &g_st.ln, &g_st.en);
	if (!(g_west.img))
		if (!(g_west.img = mlx_xpm_file_to_image(g_vars.mlx, g_we, &i, &j)))
			error_gestion(9);
	if (!(g_west.ad))
		g_west.ad = mlx_get_data_addr(g_west.img, &g_west.bpp,
					&g_west.ln, &g_west.en);
	if (!(g_east.img))
		if (!(g_east.img = mlx_xpm_file_to_image(g_vars.mlx, g_ea, &i, &j)))
			error_gestion(9);
	if (!(g_east.ad))
		g_east.ad = mlx_get_data_addr(g_east.img,
					&g_east.bpp, &g_east.ln, &g_east.en);
}

void		ray(int i)
{
	g_col.perpdist = g_rays[i].distance * cos(g_rays[i].rangle - g_pl.rtang);
	g_col.distprojection = (g_width / 2) / tan(g_pl.fov / 2);
	g_col.wallprojection = (TILE_SIZE / g_col.perpdist) * g_col.distprojection;
	g_col.strip_h = (int)g_col.wallprojection;
	g_col.walltop = (g_height / 2) - (g_col.strip_h / 2);
	g_col.walltop = g_col.walltop < 0 ? 0 : g_col.walltop;
	g_col.wallbot = (g_height / 2) + (g_col.strip_h / 2);
	g_col.wallbot = (g_col.wallbot > (int)g_height) ? g_height : g_col.wallbot;
	if (g_rays[i].g_washvert)
		g_col.xoffset = (int)g_rays[i].wallhity % TILE_SIZE;
	else
		g_col.xoffset = (int)g_rays[i].wallhitx % TILE_SIZE;
}

int			texture3d(int i)
{
	int		*j[4];
	int		dst;

	j[0] = (int *)g_n.ad;
	j[1] = (int *)g_st.ad;
	j[2] = (int *)g_west.ad;
	j[3] = (int *)g_east.ad;
	if (g_rays[i].ray_up && !g_rays[i].g_washvert)
		dst = j[1][64 * g_col.yoffset + g_col.xoffset];
	if (g_rays[i].ray_l && g_rays[i].g_washvert)
		dst = j[3][64 * g_col.yoffset + g_col.xoffset];
	if (g_rays[i].ray_d && !g_rays[i].g_washvert)
		dst = j[0][64 * g_col.yoffset + g_col.xoffset];
	if (g_rays[i].ray_r && g_rays[i].g_washvert)
		dst = j[2][64 * g_col.yoffset + g_col.xoffset];
	return (dst);
}

void		rende_3d(void)
{
	int		i;
	int		j;

	i = 0;
	texture();
	while (i < (int)g_width)
	{
		ray(i);
		j = g_col.walltop;
		while (j < g_col.wallbot)
		{
			g_col.dist = j + (g_col.strip_h / 2) - (g_height / 2);
			g_col.yoffset = (int)(g_col.dist * ((float)64 / g_col.strip_h));
			put(&g_img, i, j, texture3d(i));
			j++;
		}
		i++;
	}
}

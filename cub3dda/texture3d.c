/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 16:50:50 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/01/31 17:39:44 by sel-fcht         ###   ########.fr       */
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

	if (!(no.img))
		if (!(no.img = mlx_xpm_file_to_image(vars.mlx, g_no, &i, &j)))
			error_gestion(9);
	if (!(no.addr))
		no.addr = mlx_get_data_addr(no.img, &no.bpp, &no.ln, &no.endian);
	if (!(south.img))
		if (!(south.img = mlx_xpm_file_to_image(vars.mlx, g_so, &i, &j)))
			error_gestion(9);
	if (!(south.addr))
		south.addr = mlx_get_data_addr(south.img, &south.bpp, &south.ln, &south.endian);
	if (!(west.img))
		if (!(west.img = mlx_xpm_file_to_image(vars.mlx, g_we, &i, &j)))
			error_gestion(9);
	if (!(west.addr))
		west.addr = mlx_get_data_addr(west.img, &no.bpp,
					&west.ln, &no.endian);
	if (!(east.img))
		if (!(east.img = mlx_xpm_file_to_image(vars.mlx, g_ea, &i, &j)))
			error_gestion(9);
	if (!(east.addr))
		east.addr = mlx_get_data_addr(east.img,
					&east.bpp, &east.ln, &east.endian);
}

void		ray(int i)
{
	g_col.perpdist = rays[i].distance * cos(rays[i].rayAngle - player.rtang);
	g_col.distprojection = (g_width / 2) / tan(player.FOV / 2);
	g_col.wallprojection = (TILE_SIZE / g_col.perpdist) * g_col.distprojection;
	g_col.strip_h = (int)g_col.wallprojection;
	g_col.walltop = (g_height / 2) - (g_col.strip_h / 2);
	g_col.walltop = g_col.walltop < 0 ? 0 : g_col.walltop;
	g_col.wallbot = (g_height / 2) + (g_col.strip_h / 2);
	g_col.wallbot = (g_col.wallbot > (int)g_height) ? g_height : g_col.wallbot;
	if (rays[i].g_washvert)
		g_col.xoffset = (int)rays[i].wallhity % TILE_SIZE;
	else
		g_col.xoffset = (int)rays[i].wallhitx % TILE_SIZE;
}

int			texture3d(int i)
{
	int		*j[4];
	int		dst;

	j[0] = (int *)no.addr;
	j[1] = (int *)south.addr;
	j[2] = (int *)west.addr;
	j[3] = (int *)east.addr;
	if (rays[i].ray_up && !rays[i].g_washvert)
		dst = j[1][64 * g_col.yoffset + g_col.xoffset];
	if (rays[i].ray_l && rays[i].g_washvert)
		dst = j[0][64 * g_col.yoffset + g_col.xoffset];
	if (rays[i].ray_d && !rays[i].g_washvert)
		dst = j[3][64 * g_col.yoffset + g_col.xoffset];
	if (rays[i].ray_r && rays[i].g_washvert)
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
			my_mlx_pixel_put(&img, i, j, texture3d(i));
			j++;
		}
		i++;
	}
}

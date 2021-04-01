/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 16:47:28 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/02/03 18:56:11 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		render2(void)
{
	update();
	draw_map();
	floor_ceiling();
	cast_rays();
	rende_3d();
	sprite();
	mlx_put_image_to_window(g_vars.mlx, g_vars.mlx_wind, g_img.img, 0, 0);
}

int			walls(float x, float y)
{
	int		i;
	int		j;

	i = floor(x / TILE_SIZE);
	j = floor(y / TILE_SIZE);
	if (x < 0 || x > (g_mwidth * TILE_SIZE) ||
		y < 0 || y > (g_mheight * TILE_SIZE))
		return (1);
	if (g_allmap_with_spaces[j][i] == '1')
		return (1);
	else
		return (0);
}

void		update(void)
{
	float	x;
	float	y;
	float	move;

	g_pl.rtang += g_pl.tdirec * g_pl.rspeed;
	move = g_pl.wdirec * g_pl.mspeed;
	x = g_pl.x + cos(g_pl.rtang + g_pl.side_step) * move;
	y = g_pl.y + sin(g_pl.rtang + g_pl.side_step) * move;
	if ((!walls(g_pl.x, y + 10)) && (!walls(g_pl.x, y - 10))
		&& !has_sp(g_pl.x, y))
	{
		g_pl.y = y;
	}
	if ((!walls(x + 10, g_pl.y)) && (!walls(x - 10, g_pl.y))
		&& !has_sp(x, g_pl.y))
	{
		g_pl.x = x;
	}
}

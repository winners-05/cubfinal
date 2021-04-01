/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:31:46 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/02/02 13:01:46 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		horizontal(float angle)
{
	g_ray.ystep = TILE_SIZE;
	g_ray.ystep *= g_ray_up ? -1 : 1;
	g_ray.xstep = TILE_SIZE / tan(angle);
	g_ray.xstep *= (g_ray_l && g_ray.xstep > 0) ? -1 : 1;
	g_ray.xstep *= (g_ray_r && g_ray.xstep < 0) ? -1 : 1;
	g_ray.nexthorx = g_ray.g_xinter;
	g_ray.nexthory = g_ray.g_yintercept;
	while (g_ray.nexthorx >= 0 && g_ray.nexthorx <= g_mwidth * TILE_SIZE &&
		g_ray.nexthory >= 0 && g_ray.nexthory <= g_mheight * TILE_SIZE)
	{
		g_ray.xc = g_ray.nexthorx;
		g_ray.yc = g_ray.nexthory + (g_ray_up ? -1 : 0);
		if (walls(g_ray.xc, g_ray.yc))
		{
			g_ray.horzhitx = g_ray.nexthorx;
			g_ray.horzhity = g_ray.nexthory;
			g_ray.foundhorzhit = 1;
			break ;
		}
		else
		{
			g_ray.nexthorx += g_ray.xstep;
			g_ray.nexthory += g_ray.ystep;
		}
	}
}

void		vertical(float angle)
{
	g_ray.xstep = TILE_SIZE;
	g_ray.xstep *= g_ray_l ? -1 : 1;
	g_ray.ystep = TILE_SIZE * tan(angle);
	g_ray.ystep *= (g_ray_up && g_ray.ystep > 0) ? -1 : 1;
	g_ray.ystep *= (g_ray_d && g_ray.ystep < 0) ? -1 : 1;
	g_ray.nextverx = g_ray.g_xinter;
	g_ray.nextvery = g_ray.g_yintercept;
	while (g_ray.nextverx >= 0 && g_ray.nextverx <= g_mwidth * TILE_SIZE &&
		g_ray.nextvery >= 0 && g_ray.nextvery <= g_mheight * TILE_SIZE)
	{
		g_ray.xc = g_ray.nextverx + (g_ray_l ? -1 : 0);
		g_ray.yc = g_ray.nextvery;
		if (walls(g_ray.xc, g_ray.yc))
		{
			g_ray.verthitx = g_ray.nextverx;
			g_ray.verthity = g_ray.nextvery;
			g_ray.foundverhit = 1;
			break ;
		}
		else
		{
			g_ray.nextverx += g_ray.xstep;
			g_ray.nextvery += g_ray.ystep;
		}
	}
}

void		render_rays(int i)
{
	if (g_ray.foundhorzhit)
		g_ray.hodst = dstpnts(g_pl.x, g_pl.y, g_ray.horzhitx, g_ray.horzhity);
	else
		g_ray.hodst = FLT_MAX;
	if (g_ray.foundverhit)
		g_ray.vdist = dstpnts(g_pl.x, g_pl.y, g_ray.verthitx, g_ray.verthity);
	else
		g_ray.vdist = FLT_MAX;
	if (g_ray.vdist < g_ray.hodst)
	{
		g_rays[i].distance = g_ray.vdist;
		g_rays[i].wallhitx = g_ray.verthitx;
		g_rays[i].wallhity = g_ray.verthity;
		g_rays[i].g_washvert = 1;
	}
	else
	{
		g_rays[i].distance = g_ray.hodst;
		g_rays[i].wallhitx = g_ray.horzhitx;
		g_rays[i].wallhity = g_ray.horzhity;
		g_rays[i].g_washvert = 0;
	}
}

void		cast_wall_hit(int g_col, float columnid)
{
	columnid = angle_ray(columnid);
	g_ray_d = columnid > 0 && columnid < M_PI;
	g_ray_up = !g_ray_d;
	g_ray_r = columnid < (M_PI_2) || columnid > (1.5 * M_PI);
	g_ray_l = !g_ray_r;
	g_ray.foundhorzhit = 0;
	g_ray.horzhitx = 0;
	g_ray.horzhity = 0;
	g_ray.g_yintercept = floor(g_pl.y / TILE_SIZE) * TILE_SIZE;
	g_ray.g_yintercept += g_ray_d ? TILE_SIZE : 0;
	g_ray.g_xinter = g_pl.x + (g_ray.g_yintercept - g_pl.y) / tan(columnid);
	horizontal(columnid);
	g_ray.foundverhit = 0;
	g_ray.verthitx = 0;
	g_ray.verthity = 0;
	g_ray.g_xinter = floor(g_pl.x / TILE_SIZE) * TILE_SIZE;
	g_ray.g_xinter += g_ray_r ? TILE_SIZE : 0;
	g_ray.g_yintercept = g_pl.y + (g_ray.g_xinter - g_pl.x) * tan(columnid);
	vertical(columnid);
	render_rays(g_col);
	g_rays[g_col].rangle = columnid;
	g_rays[g_col].ray_d = g_ray_d;
	g_rays[g_col].ray_r = g_ray_r;
	g_rays[g_col].ray_up = g_ray_up;
	g_rays[g_col].ray_l = g_ray_l;
}

void		cast_rays(void)
{
	int		i;
	float	angle;

	i = 0;
	angle = g_pl.rtang - (g_pl.fov / 2);
	while (i < (int)g_width)
	{
		cast_wall_hit(i, angle);
		angle += g_pl.fov / g_width;
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:31:46 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/01/31 16:55:45 by sel-fcht         ###   ########.fr       */
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
	g_ray.nexthorX = g_ray.g_xinter;
	g_ray.nexthorY = g_ray.g_yintercept;
	while (g_ray.nexthorX >= 0 && g_ray.nexthorX <= g_mwidth * TILE_SIZE &&
		g_ray.nexthorY >= 0 && g_ray.nexthorY <= g_mheight * TILE_SIZE)
	{
		g_ray.xc = g_ray.nexthorX;
		g_ray.yc = g_ray.nexthorY + (g_ray_up ? -1 : 0);
		if (walls(g_ray.xc, g_ray.yc))
		{
			g_ray.horzhitx = g_ray.nexthorX;
			g_ray.horzhity = g_ray.nexthorY;
			g_ray.foundhorzhit = 1;
			break ;
		}
		else
		{
			g_ray.nexthorX += g_ray.xstep;
			g_ray.nexthorY += g_ray.ystep;
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
		g_ray.hodst = dstpnts(player.x, player.y, g_ray.horzhitx, g_ray.horzhity);
	else
		g_ray.hodst = FLT_MAX;
	if (g_ray.foundverhit)
		g_ray.vdist = dstpnts(player.x, player.y, g_ray.verthitx, g_ray.verthity);
	else
		g_ray.vdist = FLT_MAX;
	if (g_ray.vdist < g_ray.hodst)
	{
		rays[i].distance = g_ray.vdist;
		rays[i].wallhitx = g_ray.verthitx;
		rays[i].wallhity = g_ray.verthity;
		rays[i].g_washvert = 1;
	}
	else
	{
		rays[i].distance = g_ray.hodst;
		rays[i].wallhitx = g_ray.horzhitx;
		rays[i].wallhity = g_ray.horzhity;
		rays[i].g_washvert = 0;
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
	g_ray.g_yintercept = floor(player.y / TILE_SIZE) * TILE_SIZE;
	g_ray.g_yintercept += g_ray_d ? TILE_SIZE : 0;
	g_ray.g_xinter = player.x + (g_ray.g_yintercept - player.y) / tan(columnid);
	horizontal(columnid);
	g_ray.foundverhit = 0;
	g_ray.verthitx = 0;
	g_ray.verthity = 0;
	g_ray.g_xinter = floor(player.x / TILE_SIZE) * TILE_SIZE;
	g_ray.g_xinter += g_ray_r ? TILE_SIZE : 0;
	g_ray.g_yintercept = player.y + (g_ray.g_xinter - player.x) * tan(columnid);
	vertical(columnid);
	render_rays(g_col);
	rays[g_col].rayAngle = columnid;
	rays[g_col].ray_d = g_ray_d;
	rays[g_col].ray_r = g_ray_r;
	rays[g_col].ray_up = g_ray_up;
	rays[g_col].ray_l = g_ray_l;	
}

void		cast_rays(void)
{
	int		i;
	float	angle;

	i = 0;
	angle = player.rtang - (player.FOV / 2);
	while (i < (int)g_width)
	{
		cast_wall_hit(i, angle);
		angle += player.FOV / g_width;
		i++;
	}
}

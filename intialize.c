/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intialize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:15:20 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/02/14 17:09:01 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		intialize_player(void)
{
	g_pl.tdirec = 0;
	g_pl.wdirec = 0;
}

void		intialize_rays(float rayangle)
{
	g_ray_d = rayangle > 0 && rayangle < M_PI;
	g_ray_up = !g_ray_d;
	g_ray_r = rayangle < (M_PI_2) || rayangle > (1.5 * M_PI);
	g_ray_l = !g_ray_r;
}

int			release(int keycode)
{
	if (keycode == 13)
		g_pl.wdirec = 0;
	else if (keycode == 1)
		g_pl.wdirec = 0;
	else if (keycode == 123)
		g_pl.tdirec = 0;
	else if (keycode == 124)
		g_pl.tdirec = 0;
	else if (keycode == 2)
	{
		g_pl.side_step = 0;
		g_pl.wdirec = 0;
	}
	else if (keycode == 0)
	{
		g_pl.side_step = 0;
		g_pl.wdirec = 0;
	}
	return (0);
}

int			key_press(int keycode)
{
	if (keycode == 53)
	{
		free_memory(g_allmap_with_spaces);
		kill(g_pid, 1);
		ft_putstr("THANKS FOR PLAYING OR SCREENSHOTING");
		exit(0);
	}
	if (keycode == 13)
		g_pl.wdirec = 1;
	else if (keycode == 1)
		g_pl.wdirec = -1;
	else if (keycode == 123)
		g_pl.tdirec = -1;
	else if (keycode == 124)
		g_pl.tdirec = 1;
	else if (keycode == 2)
	{
		g_pl.side_step = M_PI_2;
		g_pl.wdirec = 1;
	}
	else if (keycode == 0)
	{
		g_pl.side_step = -M_PI_2;
		g_pl.wdirec = 1;
	}
	return (0);
}

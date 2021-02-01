/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intialize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:15:20 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/01/31 16:55:45 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		intialize_player(void)
{
	player.turnDirection = 0;
	player.walkDirection = 0;
//	player.rtang = M_PI / 2;
//	player.MoveSpeed = 2.0;
//	player.rotationSpeed = 5 * (M_PI / 180);
//	player.radius = 3;
//	player.FOV = 60 * (M_PI / 180);
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
		player.walkDirection = 0;
	else if (keycode == 1)
		player.walkDirection = 0;
	else if (keycode == 0)
		player.turnDirection = 0;
	else if (keycode == 2)
		player.turnDirection = 0;
	else if (keycode == 124)
	{
		player.side_step = 0;
		player.walkDirection = 0;
	}
	else if (keycode == 123)
	{
		player.side_step = 0;
		player.walkDirection = 0;
	}
	return (0);
}

int			key_press(int keycode)
{
	if (keycode == 53)
	{
		free_memory(g_allmap_with_spaces);
		ft_putstr("ERROR \n THANKS FOR PLAYING");
		exit(0);
	}
	if (keycode == 13)
		player.walkDirection = 1;
	else if (keycode == 1)
		player.walkDirection = -1;
	else if (keycode == 0)
		player.turnDirection = -1;
	else if (keycode == 2)
		player.turnDirection = 1;
	else if (keycode == 124)
	{
		player.side_step = M_PI_2;
		player.walkDirection = 1;
	}
	else if (keycode == 123)
	{
		player.side_step = -M_PI_2;
		player.walkDirection = 1;
	}
	return (0);
}

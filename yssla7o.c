/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yssla7o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:20:01 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/02/05 11:53:43 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float		dstpnts(float x, float y, float x0, float y0)
{
	return (sqrt(pow(x0 - x, 2) + pow(y0 - y, 2)));
}

void		floor_ceiling(void)
{
	int		i;
	int		j;
	int		fc;
	int		cc;

	i = -1;
	fc = ((g_fr & 0xff) << 16) + ((g_fg & 0xff) << 8) + (g_fb & 0xff);
	cc = ((g_cr & 0xff) << 16) + ((g_cg & 0xff) << 8) + (g_cb & 0xff);
	while (++i < (int)g_height)
	{
		j = -1;
		while (++j < (int)g_width)
		{
			if (i > (int)g_height / 2)
				put(&g_img, j, i, fc);
			else
				put(&g_img, j, i, cc);
		}
	}
}

void		render(void)
{
	update();
	draw_map();
	floor_ceiling();
	cast_rays();
	rende_3d();
	sprite();
	mlx_put_image_to_window(g_vars.mlx, g_vars.mlx_wind, g_img.img, 0, 0);
	mlx_destroy_image(g_vars.mlx, g_img.img);
}

int			play(void)
{
	mlx_hook(g_vars.mlx_wind, 2, 0, key_press, &g_vars);
	render();
	mlx_hook(g_vars.mlx_wind, 3, 0, release, &g_vars);
	mlx_hook(g_vars.mlx_wind, 17, 0, quit, &g_vars);
	return (0);
}

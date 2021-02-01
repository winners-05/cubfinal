/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yssla7o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:20:01 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/01/31 16:53:34 by sel-fcht         ###   ########.fr       */
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
				my_mlx_pixel_put(&img, j, i, fc);
			else
				my_mlx_pixel_put(&img, j, i, cc);
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
	mlx_put_image_to_window(vars.mlx, vars.mlx_wind, img.img, 0, 0);
	mlx_destroy_image(vars.mlx, img.img);
}

int			play(void)
{
	mlx_hook(vars.mlx_wind, 2, 0, key_press, &vars);
	render();
	mlx_hook(vars.mlx_wind, 3, 0, release, &vars);
	mlx_hook(vars.mlx_wind, 17, 0, quit, &vars);
	return (0);
}

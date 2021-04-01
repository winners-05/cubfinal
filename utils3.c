/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 16:47:58 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/02/03 14:22:10 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (!((x < 0 && x > (int)g_height) && (y < 0 && y > (int)g_width)))
	{
		dst = data->ad + (y * data->ln + x * (data->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

int			width_resolution(int w)
{
	int		width;
	int		i;

	width = w;
	i = 0;
	while (width != 0)
	{
		i++;
		width /= 10;
	}
	if (i > 5)
		w = 2560;
	return (w);
}

int			height_resolution(int h)
{
	int height;
	int i;

	height = h;
	i = 0;
	while (height != 0)
	{
		i++;
		height /= 10;
	}
	if (i > 5)
		h = 1440;
	return (h);
}

void		draw_map(void)
{
	g_img.img = mlx_new_image(g_vars.mlx, g_width, g_height);
	g_img.ad = mlx_get_data_addr(g_img.img, &g_img.bpp,
								&g_img.ln, &g_img.en);
}

float		angle_ray(float rayangle)
{
	rayangle = remainder(rayangle, (2 * M_PI));
	if (rayangle < 0)
		rayangle = (2 * M_PI) + rayangle;
	return (rayangle);
}

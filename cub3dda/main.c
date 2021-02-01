/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:20:08 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/01/29 18:17:09 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		read_map(void)
{
	int		fd;
	char	*line;
	int		i;

	if ((fd = open(g_file, O_RDONLY)) < 0)
	{
		ft_putstr("ERROR \n Wrong file config");
		exit(0);
	}
	while (1)
	{
		i = get_next_line(fd, &line);
		if (!(params()))
		{
			if (*line != '\0')
				map_funct(line);
		}
		else
			map_funct(line);
		if (i == 0)
			break ;
		free(line);
	}
	free(line);
	return (0);
}

void	test_arg(int ac, char *av[])
{
	int i;

	i = ft_strlen(av[1]) - 1;
	if (ac == 3)
	{
		if (av[1][i] == 'b' && av[1][i - 1] == 'u' &&
			av[1][i - 2] == 'c' && av[1][i - 3] == '.')
			g_file = ft_strdup(av[1]);
		else
			error_gestion(1);
		if (!ft_strncmp(av[2], "--save", 7))
			g_save = 1;
		else
			error_gestion(2);
	}
	else if (ac == 2)
	{
		if (av[1][i] == 'b' && av[1][i - 1] == 'u' &&
			av[1][i - 2] == 'c' && av[1][i - 3] == '.')
			g_file = ft_strdup(av[1]);
		else
			error_gestion(1);
	}
	else
		error_gestion(4);
}

int		main(int ac, char *av[])
{
	test_arg(ac, av);
	player.x = -1;
	player.y = -1;
	init_param();
	read_map();
	split_map();
	check_arrays();
	check_width();
	check_map_arrays(g_map);
	fill_g_allmap();
	vars.mlx = mlx_init();
	vars.mlx_wind = mlx_new_window(vars.mlx, g_width, g_height, "CUB3D");
	mlx_loop_hook(vars.mlx, play, 0);
	mlx_loop(vars.mlx);
	return (0);
}

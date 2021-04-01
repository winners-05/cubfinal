/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rout.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 16:45:52 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/02/09 15:52:00 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_isdigit(int c)
{
	if (c >= 0x30 && c <= 0x39)
		return (1);
	return (0);
}

int			is_digit(char *str)
{
	unsigned long long	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int			ft_atoi(const char *str)
{
	int		result;
	int		signe;

	result = 0;
	signe = 1;
	while (((*str >= 9 && *str <= 13) || *str == 32) && *str != '\0')
		str++;
	if (*str == '-')
	{
		signe = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= 48 && *str <= 57)
	{
		if (result < 0 && signe < 0)
			return (0);
		if (result < 0 && signe > 0)
			return (-1);
		result = result * 10 + *str - '0';
		str++;
	}
	return (signe * result);
}

int			re(unsigned long long width, unsigned long long height)
{
	unsigned long long	w;
	unsigned long long	h;
	unsigned long long	i;

	i = 0;
	w = width;
	h = height;
	if (height > 1440)
		h = 1440;
	if (width > 2560)
		w = 2560;
	if (width < 100 || height < 100)
	{
		ft_putstr("ERROR \nwrong resolution ");
		exit(0);
	}
	get_re(w, h);
	return (1);
}

void		get_re(unsigned long long width, unsigned long long height)
{
	g_width = width;
	g_height = height;
}

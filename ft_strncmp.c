/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:03:41 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/02/02 12:26:25 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int i;

	i = 0;
	if (*s1 == '\0')
		return ((unsigned char)*s1 - (unsigned char)*s2);
	while (*s1 && i < n)
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
			i++;
			if (*s1 == '\0')
				return ((unsigned char)*s1 - (unsigned char)*s2);
		}
		else
			return ((unsigned char)*s1 - (unsigned char)*s2);
	}
	return (0);
}

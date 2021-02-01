/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 15:50:18 by sel-fcht          #+#    #+#             */
/*   Updated: 2019/10/23 15:50:20 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*pdest;
	unsigned char	*psrc;

	pdest = (unsigned char *)dst;
	psrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		pdest[i] = psrc[i];
		if (psrc[i] == (unsigned char)c)
		{
			return (pdest + i + 1);
		}
		i++;
	}
	return (NULL);
}

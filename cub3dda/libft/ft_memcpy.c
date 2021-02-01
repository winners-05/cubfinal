/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 15:52:17 by sel-fcht          #+#    #+#             */
/*   Updated: 2019/10/23 15:53:33 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*pdest;
	unsigned char	*psrc;

	pdest = (unsigned char *)dst;
	psrc = (unsigned char *)src;
	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst == src)
		return (dst);
	if (!ft_memcmp(dst, src, n))
		return (dst);
	if (!n)
		return (dst);
	while (i < n)
	{
		*(unsigned char*)pdest = *(unsigned char*)psrc;
		psrc++;
		pdest++;
		i++;
	}
	return (dst);
}

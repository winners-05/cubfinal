/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 15:50:56 by sel-fcht          #+#    #+#             */
/*   Updated: 2019/10/23 15:50:58 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*re;

	re = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*(unsigned char*)s == (unsigned char)c)
		{
			re = (unsigned char *)s;
			return (re);
		}
		s++;
		i++;
	}
	return (NULL);
}

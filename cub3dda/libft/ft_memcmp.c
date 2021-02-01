/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 15:51:41 by sel-fcht          #+#    #+#             */
/*   Updated: 2019/10/23 15:51:42 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int i;

	i = 0;
	if (!n || (s1 != NULL && s2 == s1))
		return (0);
	while (i < n)
	{
		if (*(unsigned char*)s1 != *(unsigned char*)s2)
		{
			return (*(unsigned char*)s1 - *(unsigned char*)s2);
		}
		i++;
		s1++;
		s2++;
	}
	return (0);
}

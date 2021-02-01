/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 15:44:43 by sel-fcht          #+#    #+#             */
/*   Updated: 2019/10/23 15:44:45 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*re;
	unsigned int	i;

	i = 0;
	if (!count || !size)
	{
		count = 1;
		size = 1;
	}
	re = (unsigned char*)malloc(count * size);
	if (re == NULL)
		return (NULL);
	while (i < count * size)
	{
		re[i] = 0;
		i++;
	}
	return (re);
}

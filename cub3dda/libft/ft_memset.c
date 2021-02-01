/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 15:55:29 by sel-fcht          #+#    #+#             */
/*   Updated: 2019/10/23 15:55:30 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	unsigned char	*pb;

	if (!len)
		return (b);
	pb = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		pb[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:04:16 by sel-fcht          #+#    #+#             */
/*   Updated: 2019/10/23 16:04:17 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	if (s[i] == c)
		return ((char*)&s[i]);
	while (--i >= 0)
	{
		if (s[i] == (char)c)
			return ((char*)s + i);
	}
	return (NULL);
}

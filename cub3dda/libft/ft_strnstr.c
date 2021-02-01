/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:03:56 by sel-fcht          #+#    #+#             */
/*   Updated: 2019/10/23 16:03:58 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_val_abs(size_t l, size_t s)
{
	return ((int)l - (int)s < 0) ? s - l : l - s;
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	l;
	size_t	s;
	char	*str;

	str = (char *)haystack;
	l = 0;
	s = 0;
	while (haystack[l] != '\0')
		l++;
	while (needle[s] != '\0')
		s++;
	i = 0;
	while ((int)i <= ft_val_abs(l, s))
	{
		j = 0;
		while ((i + j < len) && (j < s) && (haystack[i + j] == needle[j]))
			j++;
		if (j == s)
			return (str + i);
		i++;
	}
	return (0);
}

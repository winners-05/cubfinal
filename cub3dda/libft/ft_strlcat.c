/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:01:31 by sel-fcht          #+#    #+#             */
/*   Updated: 2019/10/23 16:01:31 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int				i;
	int				temp;
	unsigned int	dest_len;
	unsigned int	src_len;

	dest_len = 0;
	src_len = 0;
	i = 0;
	while (src[src_len] != '\0')
		src_len++;
	while (dst[dest_len] != '\0')
		dest_len++;
	if (size <= dest_len)
		src_len = src_len + size;
	else
		src_len = src_len + dest_len;
	temp = dest_len;
	while (i < (int)size - (int)dest_len - 1 && src[i])
		dst[temp++] = src[i++];
	dst[temp] = '\0';
	return (src_len);
}

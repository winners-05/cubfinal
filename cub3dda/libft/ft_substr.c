/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:04:45 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/01/22 12:34:36 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*subs;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	while (s[start + i] != '\0' && i < len)
		i++;
	if (!(subs = (char*)malloc(i + 1)))
		return (NULL);
	i = 0;
	while (s[start + i] != '\0' && i < len)
	{
		subs[i] = s[i + start];
		i++;
	}
	subs[i] = '\0';
	free(subs);
	return (subs);
}

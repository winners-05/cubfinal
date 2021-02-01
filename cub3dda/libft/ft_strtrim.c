/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:04:30 by sel-fcht          #+#    #+#             */
/*   Updated: 2020/12/15 11:48:04 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include <stdio.h>

static int	boolchar(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	while (boolchar(s1[i], set))
		i++;
	j = ft_strlen(s1) - 1;
	while (boolchar(s1[j], set))
		j--;
	if (j < i)
		return (ft_strdup(""));
	str = ft_substr(s1, i, j - i + 1);
	return (str);
}

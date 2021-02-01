/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 15:42:01 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/01/26 15:17:24 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned long long result;
	unsigned long long signe;

	result = 0;
	signe = 1;
	len_str(str);
	while (((*str >= 9 && *str <= 13) || *str == 32) && *str != '\0')
		str++;
	if (*str == '-')
	{
		signe = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= 48 && *str <= 57)
	{
		if (result < 0 && signe < 0)
			return (0);
		if (result < 0 && signe > 0)
			return (-1);
		
		result = result * 10 + *str - '0';
		str++;
	}
	return (signe * result);
}

// char *len_str(char *str)
// {
// 	int i;
// 	i = 0;
// 	while (str[i] != '\0')
// 		i++;
// 	if (i > 8)
// 		str = "2550";
// 	return (str);
	
	
// }
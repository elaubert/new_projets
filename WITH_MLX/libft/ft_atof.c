/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 12:14:45 by eaubert           #+#    #+#             */
/*   Updated: 2021/07/08 17:48:59 by eaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

double	ft_atof(const char *str)
{
	int		i;
	int		y;
	int		sign;
	double	res;

	i = 0;
	y = 0;
	sign = 1;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
		res = (res * 10) + str[i++] - '0';
	if (str[i] == '.')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && y++ != -1)
		res = (res * 10) + str[i++] - '0';
	while (y-- > 0)
		res /= 10;
	return (res * sign);
}

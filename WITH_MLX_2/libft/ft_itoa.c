/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 12:14:45 by eaubert           #+#    #+#             */
/*   Updated: 2021/07/08 16:45:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*negatifn(long int j, char *str, int len)
{
	j *= -1;
	str[0] = '-';
	while (len > 1)
	{
		str[len - 1] = ((j % 10) + '0');
		j = j / 10;
		len--;
	}
	return (str);
}

static char	*positifn(long int j, char *str, int len)
{
	while (len >= 1)
	{
		str[len - 1] = ((j % 10) + '0');
		j = j / 10;
		len--;
	}
	return (str);
}

static long int	leen(long int n)
{
	long int	i;
	long int	nb;

	i = 0;
	if (n < 0)
	{
		nb = (n * -1);
		i++;
	}
	else
		nb = n;
	while (nb >= 10)
	{
		nb = nb / 10;
		i++;
	}
	i++;
	return (i);
}

char	*ft_itoa(int n)
{
	long int	j;
	int			len;
	char		*str;

	j = n;
	len = leen(j);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	if (j < 0)
		negatifn(j, str, len);
	else
		positifn(j, str, len);
	str[len] = '\0';
	return (str);
}

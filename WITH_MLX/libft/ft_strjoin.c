/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 12:14:45 by eaubert           #+#    #+#             */
/*   Updated: 2021/07/08 17:48:34 by eaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(char const *s1)
{
	int	i;

	i = 0;
	while (s1[i])
		i++;
	return (i);
}

static char	*concat(char *dst, char *src)
{
	int		j;
	int		i;

	i = 0;
	j = 0;
	while (dst[j])
	{
		j++;
	}
	while (src[i])
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		len_s1;
	int		len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (len_s1 + len_s2 == 0)
	{
		join = malloc(sizeof(char) * 1);
		if (join == NULL)
			return (NULL);
		join[0] = '\0';
		return (join);
	}
	join = malloc(sizeof(s1) * (len_s1 + len_s2 + 1));
	if (join == NULL)
		return (NULL);
	join[0] = '\0';
	concat(join, (char *)s1);
	concat(join, (char *)s2);
	return (join);
}

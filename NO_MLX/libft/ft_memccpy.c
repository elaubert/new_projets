/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 12:14:45 by eaubert           #+#    #+#             */
/*   Updated: 2021/01/13 14:12:50 by eaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dst_temp;
	unsigned char	*src_temp;

	i = 0;
	dst_temp = (unsigned char *)dst;
	src_temp = (unsigned char *)src;
	while (i < n)
	{
		dst_temp[i] = src_temp[i];
		if (src_temp[i] == (unsigned char)c)
			return ((unsigned char *)&dst_temp[i + 1]);
		i++;
	}
	return (NULL);
}

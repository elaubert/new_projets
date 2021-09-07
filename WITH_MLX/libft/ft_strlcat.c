/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 12:14:45 by eaubert           #+#    #+#             */
/*   Updated: 2021/01/12 18:04:26 by eaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	check_size;
	size_t	i;

	check_size = ft_strlen(dst);
	i = 0;
	if ((dstsize == 0) || (check_size > dstsize))
		return (ft_strlen(src) + dstsize);
	if (dstsize > 0)
	{
		while (src[i] && ((check_size + i) < (dstsize - 1)))
		{
			dst[check_size + i] = src[i];
			i++;
		}
		dst[check_size + i] = '\0';
	}
	return (ft_strlen(src) + check_size);
}

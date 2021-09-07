/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 12:14:45 by eaubert           #+#    #+#             */
/*   Updated: 2021/07/08 17:17:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*s_sub;
	unsigned int	len_s;
	unsigned int	i;

	i = 0;
	len_s = ft_strlen(s);
	if (len_s == '\0' || len_s < start)
	{
		s_sub = malloc(sizeof(char) * 1);
		if (s_sub == NULL)
			return (NULL);
		s_sub[0] = '\0';
		return (s_sub);
	}
	s_sub = malloc(sizeof(s) * (len + 1));
	if (s_sub == NULL)
		return (NULL);
	while (s[start] && i < len)
	{
		s_sub[i++] = s[start++];
	}
	s_sub[i] = '\0';
	return (s_sub);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaubert <eaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 12:22:02 by eaubert           #+#    #+#             */
/*   Updated: 2021/07/08 17:14:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s1_trim;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]) != NULL)
	{
		i++;
	}
	while (s1[i] && ft_strrchr(set, s1[len]) != NULL)
	{
		len--;
	}
	s1_trim = malloc(sizeof(s1) * ((len - i) + 1));
	if (s1_trim == NULL)
		return (NULL);
	while (s1[i] && (i <= (len)))
		s1_trim[j++] = s1[i++];
	s1_trim[j] = '\0';
	return (s1_trim);
}

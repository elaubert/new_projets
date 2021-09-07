/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:19:19 by eaubert           #+#    #+#             */
/*   Updated: 2021/07/08 17:48:15 by eaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**freee(char **dst, int j)
{
	while (j > 0)
	{
		j--;
		free(dst[j]);
	}
	free(dst);
	return (NULL);
}

static char	*strdup_sep(const char *s1, char c)
{
	char	*dup;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	dup = malloc(sizeof(s1) * (len + 1));
	if (dup == NULL)
		return (NULL);
	while (s1[i] && s1[i] != c)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static int	countwords(char const *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		if (i >= 1)
		{
			if (s[i] == c && s[i - 1] != c)
				j++;
		}
		i++;
	}
	if (s[i - 1] != c)
		j++;
	return (j);
}

static char	**readstr(char const *s, char c, char **tab_split)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			tab_split[j] = strdup_sep(&s[i], c);
			if (tab_split[j] == NULL)
				return (freee(tab_split, j));
			j++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	return (tab_split);
}

char	**ft_split(char const *s, char c)
{
	int		countword;
	char	**tab_split;

	if (!s)
		return (NULL);
	countword = countwords(s, c);
	tab_split = malloc(sizeof(char *) * (countword + 1));
	if (tab_split == NULL)
		return (NULL);
	tab_split[countword] = NULL;
	readstr(s, c, tab_split);
	return (tab_split);
}

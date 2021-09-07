/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaubert <eaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 16:39:39 by eaubert           #+#    #+#             */
/*   Updated: 2021/09/07 10:31:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

static char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*join;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 && s2)
	{
		join = malloc(sizeof(s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (join == NULL)
			return (NULL);
		join[0] = '\0';
		while (s1[j])
		{
			join[j] = s1[j];
			j++;
		}
		while (s2[i])
			join[j++] = s2[i++];
		join[j] = '\0';
		free(s1);
		s1 = NULL;
		return (join);
	}
	return (NULL);
}

void	free_reset(char **str)
{
	free(*str);
	*str = NULL;
}

int	rever_txt_and_checkend(char *txt, int i)
{
	int	j;
	int	check_end;

	j = 0;
	check_end = -1;
	if (txt[i] == '\n')
	{
		check_end = 1;
		i++;
	}
	while (txt[i] && i > j)
		txt[j++] = txt[i++];
	if (ft_strchr(txt, '\n') == 0 && check_end != 1)
		check_end = 0;
	txt[j] = '\0';
	return (check_end);
}

int	get_txt_in_line(char *txt, char **line)
{
	int	i;
	int	check_end;

	i = 0;
	while (txt[i] != '\n' && txt[i] != '\0')
		i++;
	*line = malloc(sizeof(char) * (i + 1));
	if (*line == NULL)
		return (0);
	i = 0;
	while (txt[i] && txt[i] != '\n' && txt[i] != '\0')
	{
		(*line)[i] = txt[i];
		i++;
	}
	(*line)[i] = '\0';
	check_end = rever_txt_and_checkend(txt, i);
	return (check_end);
}

int	get_next_line(int fd, char **line)
{
	static char	*txt;
	char		buf[11];
	int			i;

	i = 1;
	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	if (txt == NULL)
	{
		txt = malloc(sizeof(char) * 1);
		if (txt == NULL)
			return (-1);
		txt[0] = '\0';
	}
	while (i > 0 && (ft_strchr(txt, '\n') == 0))
	{
		ft_memset(buf, 0, 11);
		i = read(fd, buf, 10);
		txt = ft_strjoin_free(txt, buf);
	}
	i = get_txt_in_line(txt, line);
	if (i != 0)
		return (1);
	free_reset(&txt);
	return (0);
}

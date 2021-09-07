/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaubert <eaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 11:46:10 by eaubert           #+#    #+#             */
/*   Updated: 2021/09/07 14:47:35 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**free_tab(char **dst, int j)
{
	while (j > 0)
	{
		j--;
		free(dst[j]);
	}
	free(dst);
	dst = NULL;
	return (NULL);
}

void	fill_map(char *argv, t_map *map)
{
	char	*line;
	int		fd;
	int		ret;
	int		i;

	fd = open(argv, O_RDONLY);
	i = 0;
	ret = get_next_line(fd, &line);
	while (ret > 0)
	{
		map->tab_map[i] = ft_strdup(line);
		i++;
		free(line);
		ret = get_next_line(fd, &line);
	}
	if (ret == 0 && line[0])
		map->tab_map[i] = ft_strdup(line);
	free(line);
	close(fd);
}

int	count_line(char *argv, t_map *map, int fd, int ret)
{
	char	*line;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		printf("%s\n", strerror(errno));
		exit(1);
	}
	ret = get_next_line(fd, &line);
	while (ret > 0)
	{
		map->nb_line++;
		free(line);
		ret = get_next_line(fd, &line);
	}
	if (ret == 0 && line[0])
		map->nb_line++;
	else if (ret == -1)
	{
		printf("%s\n", strerror(errno));
		exit(1);
	}
	free(line);
	close(fd);
	return (map->nb_line);
}

void	lets_play(t_map *map, char **argv)
{
	t_render	*frame;

	map->tab_map[map->nb_line] = NULL;
	fill_map(argv[1], map);
	check_map(map);
	frame = init_frame();
	frame->map = map;
	my_mlx_init(frame);
	render_loop(frame);
}

int	main(int argc, char **argv)
{
	t_map		map;
	int			len_arg;

	map = init_map();
	if (argc != 2)
	{
		printf("Error\nOne argument needed.\n");
		return (-1);
	}
	len_arg = ft_strlen(argv[1]);
	if (argv[1][len_arg - 4] != '.' || (argv[1][len_arg - 3] != 'b'
				|| argv[1][len_arg - 2] != 'e' || argv[1][len_arg - 1] != 'r' ))
	{
		printf("Error\nNot .ber extension.\n");
		return (-1);
	}
	map.tab_map = malloc(sizeof(char *) * (count_line(argv[1], &map, 0, \
	0) + 1));
	if (map.tab_map == NULL)
	{
		printf("%s\n", strerror(errno));
		return (1);
	}
	lets_play(&map, argv);
	return (0);
}

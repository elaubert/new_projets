/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaubert <eaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 11:46:10 by eaubert           #+#    #+#             */
/*   Updated: 2021/09/07 14:31:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_validity(t_map *map)
{
	if (map->exit != 1 || map->collect < 1 || map->player != 1)
	{
		printf("Error\nNeed one exit, one player and one or more collect\n");
		free_tab(map->tab_map, map->nb_line);
		exit(1);
	}	
}

void	check_car(char car, t_map *map, int i, int j)
{
	if (car != '1' && car != '0' && car != 'C' && car != 'E' && car != 'P')
	{
		printf("Error\nAllowed characters : 1, 0, C, E, P.\n");
		free_tab(map->tab_map, map->nb_line);
		exit(1);
	}
	if (car == 'C')
		map->collect++;
	if (car == 'E')
		map->exit++;
	if (car == 'P')
	{
		map->player_pos[0] = i;
		map->player_pos[1] = j;
		map->player++;
	}
}

void	check_first_n_last_lines(t_map *map, int i)
{
	int	car;
	int	len_line;

	car = 0;
	if (map->tab_map[i])
	{
		map->hei_map++;
		len_line = ft_strlen(map->tab_map[i]);
		while (map->tab_map[i][car])
		{
			if (map->tab_map[i][car] != '1' || len_line != map->len_map)
			{
				printf("Error\nMap must be square and walls only char. 1.\n");
				free_tab(map->tab_map, map->nb_line);
				exit(1);
			}
			car++;
		}
	}
	if (map->hei_map < 2 && i > 0)
	{
		printf("Error\nMap should have at leat 2 lignes.\n");
		free_tab(map->tab_map, map->nb_line);
		exit(1);
	}
}

int	check_center_lines(t_map *map, int i, int car)
{
	int	len_line;

	while (map->tab_map[i + 1])
	{
		map->hei_map++;
		car = 0;
		len_line = ft_strlen(map->tab_map[i]);
		if (map->tab_map[i][car] != '1' || map->tab_map[i][len_line - 1] != '1'
				|| len_line != map->len_map)
		{
			printf("Error\nInvalid map : must be a square and close with 1.\n");
			free_tab(map->tab_map, map->nb_line);
			exit(1);
		}
		while (map->tab_map[i][car])
		{
			check_car(map->tab_map[i][car], map, i, car);
			car++;
		}
		i++;
	}
	return (i);
}

void	check_map(t_map *map)
{
	int	i;
	int	car;

	i = 0;
	car = 0;
	if (map->nb_line == 0)
	{
		printf("Error\nInvalid map : empty file.\n");
		free_tab(map->tab_map, map->nb_line);
		exit(1);
	}
	map->len_map = ft_strlen(map->tab_map[i]);
	map->wid_map = map->len_map;
	check_first_n_last_lines(map, i);
	i++;
	i = check_center_lines(map, i, car);
	check_first_n_last_lines(map, i);
	check_map_validity(map);
}

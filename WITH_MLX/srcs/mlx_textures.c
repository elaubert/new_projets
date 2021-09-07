/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 11:08:52 by user42            #+#    #+#             */
/*   Updated: 2021/09/07 11:54:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_texture(t_render *frame)
{
	frame->ground = mlx_xpm_file_to_image(frame->mlx,
			"./textures/grd.xpm", &frame->map->wid_txt, &frame->map->hei_txt);
	frame->play = mlx_xpm_file_to_image(frame->mlx,
			"./textures/play.xpm", &frame->map->wid_txt, &frame->map->hei_txt);
	frame->wall = mlx_xpm_file_to_image(frame->mlx,
			"./textures/wall.xpm", &frame->map->wid_txt, &frame->map->hei_txt);
	frame->exi = mlx_xpm_file_to_image(frame->mlx,
			"./textures/exi.xpm", &frame->map->wid_txt, &frame->map->hei_txt);
	frame->coll = mlx_xpm_file_to_image(frame->mlx,
			"./textures/coll.xpm", &frame->map->wid_txt, &frame->map->hei_txt);
	texture_error(frame);
	print_texture(frame);
	return (0);
}

void	put_textures_sprit(t_render *frame, int i, int j)
{
	if (frame->map->tab_map[i][j] == '1')
		mlx_put_image_to_window(frame->mlx, frame->win,
			frame->wall, j * 64, i * 64);
	else if (frame->map->tab_map[i][j] == '0')
		mlx_put_image_to_window(frame->mlx, frame->win,
			frame->ground, j * 64, i * 64);
	else if (frame->map->tab_map[i][j] == 'E')
		mlx_put_image_to_window(frame->mlx, frame->win,
			frame->exi, j * 64, i * 64);
	else if (frame->map->tab_map[i][j] == 'C')
		mlx_put_image_to_window(frame->mlx, frame->win,
			frame->coll, j * 64, i * 64);
	else if (frame->map->tab_map[i][j] == 'P')
		mlx_put_image_to_window(frame->mlx, frame->win,
			frame->play, j * 64, i * 64);
}

void	print_texture(t_render *frame)
{
	int	i;
	int	j;

	i = 0;
	while (frame->map->tab_map[i])
	{
		j = 0;
		while (frame->map->tab_map[i][j])
		{
			put_textures_sprit(frame, i, j);
			j++;
		}
		i++;
	}
}

void	texture_error(t_render *frame)
{
	if (frame->ground == NULL || frame->wall == NULL || frame->play == NULL || \
			frame->exi == NULL || frame->coll == NULL)
	{
		free_tab(frame->map->tab_map, frame->map->nb_line);
		mlx_destroy_window(frame->mlx, frame->win);
		frame->win = NULL;
		mlx_destroy_image(frame->mlx, frame->img);
		destroy_img_sprit(frame);
		frame->img = NULL;
		frame->addr = NULL;
		mlx_destroy_display(frame->mlx);
		free(frame->mlx);
		frame->mlx = NULL;
		free(frame);
		frame = NULL;
		printf("Graphic system failed (mlx connection).\nTry again.\n");
		exit(1);
	}
}

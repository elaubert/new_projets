/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 11:08:52 by user42            #+#    #+#             */
/*   Updated: 2021/09/07 14:50:45 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_loop(t_render *frame)
{
	mlx_hook(frame->win, 33, 1L << 17, close_wind, frame);
	mlx_hook(frame->win, 15, 1L << 16, init_texture, frame);
	mlx_key_hook(frame->win, key_hook, frame);
	mlx_loop(frame->mlx);
}

void	my_mlx_init(t_render *frame)
{
	frame->mlx = mlx_init();
	if (frame->mlx == NULL)
	{
		printf("Error\n");
		printf("mlx failled, should be an environement mistake");
		exit(0);
	}
	frame->win = mlx_new_window(frame->mlx, (frame->map->wid_map * 64),
			(frame->map->hei_map * 64), "so_long");
	frame->img = mlx_new_image(frame->mlx, (frame->map->wid_map * 64),
			(frame->map->hei_map * 64));
	frame->addr = mlx_get_data_addr(frame->img, &frame->bits_per_pixel,
			&frame->line_length, &frame->endian);
	mlx_error(frame);
}

void	mlx_error(t_render *frame)
{
	if (frame == NULL || frame->mlx == NULL || \
			frame->win == NULL || frame->img == NULL || frame->addr == NULL)
	{
		free_tab(frame->map->tab_map, frame->map->nb_line);
		mlx_destroy_window(frame->mlx, frame->win);
		frame->win = NULL;
		mlx_destroy_image(frame->mlx, frame->img);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 11:08:52 by user42            #+#    #+#             */
/*   Updated: 2021/09/09 10:43:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CHANGE.h"

int	mouse_hook(int button, int x, int y, t_render *frame)
{
	(void)x;
	(void)y;
	if (button == 3)
		mlx_mouse_show(frame->mlx, frame->win);
	if (button == 1)
		mlx_mouse_hide(frame->mlx, frame->win);
	return (0);
}

int	key_hook(int keycode, t_render *frame)
{
	if (keycode == ESC)
		close_wind(frame);
	return (0);
}

int	close_wind(t_render *frame)
{
	mlx_loop_end(frame->mlx);
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
	exit(0);
}

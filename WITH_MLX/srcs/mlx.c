/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 11:08:52 by user42            #+#    #+#             */
/*   Updated: 2021/09/09 10:43:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CHANGE.h"

t_render    *init_frame()
{
    t_render *frame;

    frame = malloc(sizeof(t_render));
    if (!frame)
        return (NULL);
    frame->address_add = NULL;
    frame->mlx = NULL;
    frame->win = NULL;
    frame->img = NULL;
    frame->addr = NULL;
    frame->bits_per_pixel = -1;
    frame->line_length = -1;
    frame->endian = -1;
    frame->error = 0;
    return (frame);
}

void    mlx_render_loop(char **argv, t_render *frame)
{
	(void)argv;
    mlx_hook(frame->win, 15, 1L<<16, put_img_to_win, frame);
    mlx_hook(frame->win, 33, 1L<<17, close_wind, frame);
    mlx_mouse_hook(frame->win, mouse_hook, frame);
    mlx_key_hook(frame->win, key_hook, frame);
	mlx_put_image_to_window(frame->mlx, frame->win, frame->img, 0, 0);
    mlx_loop(frame->mlx);
}

void	my_mlx_init(t_render *frame)
{
    frame->mlx = mlx_init();
	if (frame->mlx == NULL)
	{
		printf("Mlx failled"); // VOIR SI AUTORISE et CHANGER MESSAGE
		free(frame);
		frame = NULL;
		exit(1);
	}
    frame->win = mlx_new_window(frame->mlx, (int)WID, (int)HEI, "so_long");
    frame->img = mlx_new_image(frame->mlx, (int)WID, (int)HEI);
    frame->addr = mlx_get_data_addr(frame->img, &frame->bits_per_pixel, \
    &frame->line_length, &frame->endian);
    mlx_error(frame);
}

void    mlx_error(t_render *frame)
{
    if (frame == NULL || frame->mlx == NULL || \
            frame->win == NULL || frame->img == NULL || frame->addr == NULL)
    {
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

int put_img_to_win(t_render *frame)
{
    mlx_put_image_to_window(frame->mlx, frame->win, frame->img, 0, 0);
    return (0);
}

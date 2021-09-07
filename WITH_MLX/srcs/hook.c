/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 11:08:52 by user42            #+#    #+#             */
/*   Updated: 2021/09/07 14:15:05 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	move_player(t_render *frame, int i, int j, int zer)
{
	if (frame->map->tab_map[i][j] == '1' || (frame->map->tab_map[i][j] == 'E' \
				&& frame->map->collect != 0))
		return (1);
	else if (frame->map->tab_map[i][j] == 'E' && frame->map->collect == 0)
		close_wind(frame);
	else if (frame->map->tab_map[i][j] == 'C')
		frame->map->collect--;
	frame->map->tab_map[frame->map->player_pos[0]] \
	[frame->map->player_pos[1]] = '0';
	frame->map->tab_map[i][j] = 'P';
	if (zer == 1)
		frame->map->player_pos[0] -= 1;
	else if (zer == 2)
		frame->map->player_pos[0] += 1;
	else if (zer == 3)
		frame->map->player_pos[1] -= 1;
	else if (zer == 4)
		frame->map->player_pos[1] += 1;
	destroy_img_sprit(frame);
	init_texture(frame);
	return (0);
}

int	player_move(int nb_move, int keycode, t_render *frame)
{
	int	ret;

	ret = 0;
	if (keycode == UP || keycode == W_UP)
		ret = move_player(frame, frame->map->player_pos[0] - 1, \
		frame->map->player_pos[1], 1);
	else if (keycode == DO || keycode == S_DO)
		ret = move_player(frame, frame->map->player_pos[0] + 1, \
		frame->map->player_pos[1], 2);
	else if (keycode == LE || keycode == A_LE)
		ret = move_player(frame, frame->map->player_pos[0], \
		frame->map->player_pos[1] - 1, 3);
	else if (keycode == RI || keycode == D_RI)
		ret = move_player(frame, frame->map->player_pos[0], \
		frame->map->player_pos[1] + 1, 4);
	else
	{
		nb_move = 0;
		return (-1);
	}
	return (ret);
}

int	key_hook(int keycode, t_render *frame)
{
	static int	nb_move;
	int			res;

	if (keycode == ESC)
		close_wind(frame);
	res = player_move(nb_move, keycode, frame);
	if (res == 0)
		nb_move += 1;
	else
		return (0);
	green();
	printf("number of movement [%d]\n", nb_move);
	reset();
	return (0);
}

void	destroy_img_sprit(t_render *frame)
{
	mlx_destroy_image(frame->mlx, frame->ground);
	mlx_destroy_image(frame->mlx, frame->wall);
	mlx_destroy_image(frame->mlx, frame->play);
	mlx_destroy_image(frame->mlx, frame->exi);
	mlx_destroy_image(frame->mlx, frame->coll);
}

int	close_wind(t_render *frame)
{
	free_tab(frame->map->tab_map, frame->map->nb_line);
	mlx_loop_end(frame->mlx);
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
	exit(0);
}

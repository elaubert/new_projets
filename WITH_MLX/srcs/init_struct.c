/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaubert <eaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 10:53:52 by eaubert           #+#    #+#             */
/*   Updated: 2021/09/07 11:15:42 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	init_map(void)
{
	t_map	map;

	map.tab_map = NULL;
	map.player_pos[0] = 0;
	map.player_pos[1] = 0;
	map.nb_line = 0;
	map.len_map = 0;
	map.wid_map = 0;
	map.wid_txt = 0;
	map.hei_map = 0;
	map.hei_txt = 0;
	map.exit = 0;
	map.collect = 0;
	map.player = 0;
	return (map);
}

t_render	*init_frame(void)
{
	t_render	*frame;

	frame = malloc(sizeof(t_render));
	if (!frame)
		return (NULL);
	frame->ground = NULL;
	frame->wall = NULL;
	frame->play = NULL;
	frame->exi = NULL;
	frame->coll = NULL;
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

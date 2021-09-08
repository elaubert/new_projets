/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 11:08:52 by user42            #+#    #+#             */
/*   Updated: 2021/09/01 11:07:59 by eaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	trgb_generator(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_render *frame, int x, int y, int color)
{
	char	*dst;

	dst = frame->addr + ((x * 4) + (y * frame->line_length));	
	*(unsigned int*)dst = color;
}

void	check_pixel_intensity(t_render *frame)
{
	(void)frame;
/*	(void)values;
	if (vec->pixel_intensity.r <= 0)
		vec->pixel_intensity.r = 0;
	if (vec->pixel_intensity.g <= 0)
		vec->pixel_intensity.g = 0;
	if (vec->pixel_intensity.b <= 0)
		vec->pixel_intensity.b = 0;
	if (vec->pixel_intensity.r >= 255)
		vec->pixel_intensity.r = 255;
	if (vec->pixel_intensity.g >= 255)
		vec->pixel_intensity.g = 255;
	if (vec->pixel_intensity.b >= 255)
		vec->pixel_intensity.b = 255;*/
}

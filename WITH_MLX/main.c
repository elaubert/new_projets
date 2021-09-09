/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaubert <eaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 11:46:10 by eaubert           #+#    #+#             */
/*   Updated: 2021/09/09 10:42:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CHANGE.h"

int	main(int argc, char **argv)
{
	t_render *frame;

	(void)argc;
	frame = init_frame();
	my_mlx_init(frame);
	mlx_render_loop(argv, frame);
	return (0);
}

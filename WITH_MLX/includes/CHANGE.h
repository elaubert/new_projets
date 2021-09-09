/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:17:53 by user42            #+#    #+#             */
/*   Updated: 2021/09/09 10:40:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANGE_H
# define CHANGE_H
# include <mlx.h>
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <unistd.h>
# include <math.h> // VOIR SI AUTORISE

# define ESC 65307
# define WID 1280 // SELON SUJET 
# define HEI 720 // SELON SUJET

typedef struct	s_render
{
	void 	*address_add;
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		error;
}		t_render;

t_render    *init_frame(void); // mlx
void    	mlx_render_loop(char **argv, t_render *frame); // mlx
void		my_mlx_init(t_render *frame); // mlx
void    	mlx_error(t_render *frame); //mlx
int			put_img_to_win(t_render *frame); // mlx
int			mouse_hook(int button, int x, int y, t_render *frame);
int			key_hook(int keycode, t_render *frame);
int			close_wind(t_render *frame);
//void		my_mlx_pixel_put(t_render *frame, int x, int y, int color); VOIR IS AUTORISE

#endif

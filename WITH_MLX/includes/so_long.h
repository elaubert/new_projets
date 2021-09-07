/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:17:53 by user42            #+#    #+#             */
/*   Updated: 2021/09/07 14:43:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
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
# include <math.h>

# define ESC 65307
# define W_UP 119
# define A_LE 97
# define S_DO 115
# define D_RI 100
# define UP 65362
# define LE 65361
# define DO 65364
# define RI 65363

typedef struct s_map
{
	char	**tab_map;
	int		player_pos[2];
	int		nb_line;
	int		len_map;
	int		wid_map;
	int		wid_txt;
	int		hei_map;
	int		hei_txt;
	int		exit;
	int		collect;
	int		player;
}		t_map;

typedef struct s_render
{
	void			*ground;
	void			*wall;
	void			*play;
	void			*exi;
	void			*coll;
	void			*address_add;
	void			*mlx;
	void			*win;
	void			*img;
	void			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				error;
	t_map			*map;
}		t_render;

t_map		init_map(void);
void		lets_play(t_map *map, char **argv);
void		check_map(t_map *map);
void		check_first_n_last_lines(t_map *map, int i);
int			check_center_lines(t_map *map, int i, int car);
void		check_car(char car, t_map *map, int i, int j);
void		check_map_validity(t_map *map);
char		**free_tab(char **dst, int j);
int			check_args(int argc, char **argv);
int			count_line(char *argv, t_map *map, int fd, int ret);
void		fill_map(char *argv, t_map *map);
int			get_next_line(int fd, char **line);
int			key_hook(int keycode, t_render *frame);
int			close_wind(t_render *frame);
t_render	*init_frame(void);
void		my_mlx_init(t_render *frame);
void		mlx_error(t_render *frame);
void		render_loop(t_render *frame);
int			init_texture(t_render *frame);
void		print_texture(t_render *frame);
void		put_textures_sprit(t_render *frame, int i, int j);
void		texture_error(t_render *frame);
void		destroy_img_sprit(t_render *frame);
int			player_move(int nb_move, int keycode, t_render *frame);
void		green(void);
void		reset(void);

#endif

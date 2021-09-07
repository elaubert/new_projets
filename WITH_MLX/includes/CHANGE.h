/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CHANGE.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:17:53 by user42            #+#    #+#             */
/*   Updated: 2021/09/07 17:23:56 by user42           ###   ########.fr       */
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
# include <math.h> // A VOIR SI PERMIS

typedef struct s_map
{
	char	**CHANGE;
	int		CHANGE[2];
	int		CHANGE;
}		t_map;

typedef struct s_render
{
	void			*address_add;
	void			*mlx;
	void			*win;
	void			*img;
	void			*addr;
	int				bits_per_pixel;
}		t_render;

void		green(void);
void		reset(void);

#endif

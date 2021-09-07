# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eaubert <eaubert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/08 17:11:01 by eaubert           #+#    #+#              #
#    Updated: 2021/09/07 15:42:33 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= so_long

INCLU	= -I./includes

FILE_PATH_DISPLAY	= ./srcs

CC 		= clang

CFLAGS 	= -Wall -Wextra -Werror

FRACTOL	= main.c 

FILE_DISPLAY = get_next_line.c hook.c mlx.c map_parsing.c init_struct.c \
			   color.c mlx_textures.c


SRCS	=  $(FRACTOL) $(addprefix $(FILE_PATH_DISPLAY)/, $(FILE_DISPLAY))

OBJS 	= ${SRCS:.c=.o}

RM	= rm -f

MLX = 'mlx_linux */'

all: 		${NAME}

%.o : %.c
	
	  $(CC) $(CFLAGS) -g $(INCLU) $(INCLU_LIBFT) -c $< -o $@

$(NAME):	${OBJS}
		cp  includes/libft.h libft/
		make -C libft/ bonus
		make -C mlx_linux/
		$(CC) $(CFLAGS) ${OBJS} -g -Lmlx_linux -lmlx_linux -L/usr/lib -lXext -lX11 -lm -o $(NAME) libft/libft.a

clean:
			${RM} ${OBJS}
			make -C libft/ clean
			make -C mlx_linux/ clean
			${RM} libft/libft.a
			${RM} libft/libft.h

fclean:		clean
			  ${RM} ${NAME}

re: 		fclean all

.PHONY:		all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eaubert <eaubert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/08 17:11:01 by eaubert           #+#    #+#              #
#    Updated: 2021/09/30 12:00:51 by eaubert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= CHANGE

INCLU	= -I./includes -I./mlx_linux

FILE_PATH_DISPLAY	= ./srcs

CC 		= clang

CFLAGS 	= -Wall -Wextra -Werror

MLX 	= -Lmlx_linux -lmlx_linux -lXext -lX11 -lm 

MAIN	= main.c 

FILE_DISPLAY = hook.c mlx.c color.c \

SRCS	=  $(MAIN) $(addprefix $(FILE_PATH_DISPLAY)/, $(FILE_DISPLAY))

OBJS 	= ${SRCS:.c=.o}

RM	= rm -f

all: 		${NAME}

%.o : %.c
	
	  $(CC) $(CFLAGS) $(INCLU) -c $< -o $@

$(NAME):	${OBJS}
		cp  includes/libft.h libft/
		make -C libft/ bonus
		make -C mlx_linux/
		$(CC) $(CFLAGS) ${OBJS} $(MLX) -o $(NAME) libft/libft.a

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

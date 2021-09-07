# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eaubert <eaubert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/08 17:11:01 by eaubert           #+#    #+#              #
#    Updated: 2021/09/07 17:09:29 by eaubert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= /*CHANGE*/

INCLU	= -I./includes

FILE_PATH_DISPLAY	= ./srcs

CC 		= clang

CFLAGS 	= -Wall -Wextra -Werror

/*CHANGE*/	= main.c 

FILE_DISPLAY = \


SRCS	=  $(/*CHANGE*/) $(addprefix $(FILE_PATH_DISPLAY)/, $(FILE_DISPLAY))

OBJS 	= ${SRCS:.c=.o}

RM	= rm -f

all: 		${NAME}

%.o : %.c
	
	  $(CC) $(CFLAGS) $(INCLU)  -c $< -o $@

$(NAME):	${OBJS}
		cp  includes/libft.h libft/
		make -C libft/ bonus
		$(CC) $(CFLAGS) ${OBJS} -g3 -fsanitize=address -o $(NAME) libft/libft.a

clean:
			${RM} ${OBJS}
			make -C libft/ clean
			${RM} libft/libft.a
			${RM} libft/libft.h

fclean:		clean
			  ${RM} ${NAME}

re: 		fclean all

.PHONY:		all clean fclean re

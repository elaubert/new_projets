# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eaubert <eaubert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/08 17:11:01 by eaubert           #+#    #+#              #
#    Updated: 2021/07/08 17:47:56 by eaubert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= libft.a

CC 		= clang

CFLAGS 	= -Wall -Wextra -Werror

SRCS 	= ft_calloc.c ft_isascii.c ft_itoa.c ft_memcmp.c \
		  ft_memset.c ft_putnbr_fd.c ft_strchr.c ft_strlcat.c ft_strmapi.c \
		  ft_strrchr.c ft_tolower.c ft_atoi.c ft_isalnum.c ft_isdigit.c \
		  ft_memccpy.c ft_memcpy.c ft_putchar_fd.c ft_putstr_fd.c \
		  ft_strdup.c ft_strlcpy.c ft_strncmp.c ft_strtrim.c ft_toupper.c \
		  ft_bzero.c ft_isalpha.c ft_isprint.c ft_memchr.c \
		  ft_putendl_fd.c ft_split.c ft_strjoin.c ft_strlen.c ft_strnstr.c \
			  ft_substr.c ft_atof.c

SRCS_B 	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		  ft_lstadd_back.c 

OBJS 	= ${SRCS:.c=.o}

OBJS_B 	= ${SRCS_B:.c=.o}

HEADER 	= libft.h

RM		= rm -f

all: 		${NAME}

.c.o:
			@ ${CC} ${CFLAGS} -c $< -o $@

bonus:		${OBJS} ${OBJS_B}

			@ ar rc $(NAME) ${OBJS} ${OBJS_B}	

$(NAME): 	${OBJS}

			@ ar rc $(NAME) ${OBJS}
clean:
			@ ${RM} ${OBJS} ${OBJS_B}

fclean:		clean
			@ ${RM} ${NAME}

re: 		fclean all

.PHONY:		all bonus clean fclean re

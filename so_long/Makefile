# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 07:03:20 by dmontoro          #+#    #+#              #
#    Updated: 2022/08/30 17:59:23 by dmontoro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

CC	= gcc

FLAGS	= #-Wall -Werror -Wextra -g3 -O0 -fsanitize=address -D BUFFER_SISE=42

RM	= rm -f

SRCS	= main.c so_long.h\

OBJ	= ${SRCS:.c=.o}

MLX = mlx

MLXDIR = ./mlx/

MLXNAME = libmlx.a

MLXFLAGS = -framework OpenGL -framework AppKit

MLXPATH = ${MLXDIR}${MLXNAME}

.c.o:
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJ} ${MLXPATH}
				${CC} ${CFLAGS} -L${MLXDIR} -l${MLX} ${MLXFLAGS} ${OBJ} -o ${NAME}

${MLXPATH}:
				@make -C ${MLXDIR}

bonus:		all ${OBJB}
				@make OBJ="${OBJB}"

all:		${NAME}

clean:
				${RM} ${OBJ} ${OBJB}
				make clean -C ${MLXDIR}

fclean: 	clean
				${RM} ${NAME}

re: 		fclean all

rebonus:	fclean bonus

.PHONY:		all bonus clean fclean re rebonus
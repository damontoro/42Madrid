# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 07:03:20 by dmontoro          #+#    #+#              #
#    Updated: 2022/10/08 11:35:04 by dmontoro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

CC	= gcc

FLAGS	= #-Wall -Werror -Wextra -g3 -O0 -fsanitize=address -D BUFFER_SISE=42

RM	= rm -f

SRCS	= so_long.c\

OBJ	= ${SRCS:.c=.o}

MLX = mlx

MLXDIR = ./libs/mlx/

MLXNAME = libmlx.a

MLXFLAGS = -framework OpenGL -framework AppKit

MLXPATH = ${MLXDIR}${MLXNAME}

LIBFT = ft

LIBFTDIR = ./libs/libft/

LIBFTNAME = libft.a

LIBFTPATH = ${LIBFTDIR}${LIBFTNAME}

.c.o:
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJ} ${MLXPATH} ${LIBFTPATH}
				${CC} ${CFLAGS} -L${MLXDIR} -L${LIBFTDIR} -l${MLX} -l${LIBFT} ${MLXFLAGS} ${OBJ} -o ${NAME}

${MLXPATH}:
				@make -C ${MLXDIR}

${LIBFTPATH}:
				@MAKE -C ${LIBFTDIR}

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
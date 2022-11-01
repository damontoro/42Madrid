# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 07:03:20 by dmontoro          #+#    #+#              #
#    Updated: 2022/10/08 11:56:30 by dmontoro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

CC	= gcc

CFLAGS	= -g -O0 -D BUFFER_SIZE=42 -Wall -Werror -Wextra -fsanitize=address

RM	= rm -f

SRCS	= so_long.c \
			algorithms.c auxFunctions2.c \
			mapParser.c auxFunctions.c \
			utils/get_next_line.c utils/get_next_line_utils.c utils/utils.c

OBJ	= ${SRCS:.c=.o}

MLX = mlx

MLXDIR = ./libs/mlx/

MLXNAME = libmlx.a

MLXFLAGS = -framework OpenGL -framework AppKit

MLX_LINUX = mlx_Linux

MLXDIR_LINUX = ./libs/mlx-linux/

MLXNAME_LINUX = libmlx.a

MLXPATH_LINUX = ${MLXDIR_LINUX}${MLXNAME_LINUX}

LIBFT = libft

LIBFTDIR = ./libs/libft/

LIBFTNAME = libft.a

LIBFTPATH = ${LIBFTDIR}${LIBFTNAME}

LINUX = so_long_linux

.c.o:
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJ} ${MLXPATH} ${LIBFTPATH}
				${CC} ${CFLAGS}  ${OBJ} -L${MLXDIR} -L${LIBFTDIR} -l${MLX} -l${LIBFT} ${MLXFLAGS} -o ${NAME}

${LINUX}: ${OBJ} ${MLXPATH_LINUX} ${LIBFTPATH}
				${CC} ${CFLAGS} ${OBJ} -L${MLXDIR_LINUX} -L${LIBFTDIR} -l${MLX_LINUX} -lm -lXext -lX11 -l${LIBFT} ${MLXFLAGS_LINUX} -o ${NAME}

${MLXPATH_LINUX}:
				@make -C ${MLXDIR_LINUX}

${MLXPATH}:
				@make -C ${MLXDIR}

${LIBFTPATH}:
				@make bonus -C ${LIBFTDIR}

bonus:		all ${OBJB}
				@make OBJ="${OBJB}"

all:		${NAME}

linux:		${LINUX}

clean:
				${RM} ${OBJ} ${OBJB}
				make clean -C ${MLXDIR}
				make clean -C ${LIBFTDIR}
				make clean -C ${MLXDIR_LINUX}

fclean: 	clean
				make fclean -C ${LIBFTDIR}
				${RM} ${NAME}

re: 		fclean all

rebonus:	fclean bonus

.PHONY:		all bonus clean fclean re rebonus linux
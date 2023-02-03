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

NAME	= push_swap

CC	= gcc

CFLAGS	= -g -O0 -D BUFFER_SIZE=42 -Wall -Werror -Wextra -fsanitize=address

RM	= rm -f

SRCS	= push_swap.c inst1.c inst2.c

OBJ	= ${SRCS:.c=.o}

LIBFT = libft

LIBFTDIR = ./libs/libft/

LIBFTNAME = libft.a

LIBFTPATH = ${LIBFTDIR}${LIBFTNAME}

.c.o:
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJ} ${LIBFTPATH}
				${CC} ${CFLAGS} ${OBJ} -L${LIBFTDIR} -l${LIBFT} -o ${NAME}

${LIBFTPATH}:
				@make bonus -C ${LIBFTDIR}

bonus:		all ${OBJB}
				@make OBJ="${OBJB}"

all:		${NAME}

clean:
				${RM} ${OBJ} ${OBJB}
				make clean -C ${LIBFTDIR}

fclean: 	clean
				make fclean -C ${LIBFTDIR}
				${RM} ${NAME}

re: 		fclean all

rebonus:	fclean bonus

.PHONY:		all bonus clean fclean re rebonus
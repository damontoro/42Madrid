# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 07:03:20 by dmontoro          #+#    #+#              #
#    Updated: 2023/07/22 09:43:49 by dmontoro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CC	= gcc

CFLAGS	= -g3 -O0 -D BUFFER_SIZE=42 -Wall -Werror -Wextra

RM	= rm -f

SRCS	= push_swap.c parse.c smallsort.c bigsort.c inst1.c inst2.c inst3.c utils1.c utils2.c inserts.c

OBJ	= ${SRCS:.c=.o}

LIBFT = libft

LIBFTDIR = ./libs/libft/

LIBFTNAME = libft.a

LIBFTPATH = ${LIBFTDIR}${LIBFTNAME}

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJ} ${LIBFTPATH}
				${CC} ${CFLAGS} ${OBJ} -Iincludes ${LIBFTPATH} -o ${NAME}

${LIBFTPATH}:
				@make bonus -C ${LIBFTDIR}


all:		${NAME}

bonus:		all ${OBJB}
				@make OBJ="${OBJB}"

test:
	  ARG=`ruby -e "puts (-20..499).to_a.shuffle.join(' ')"`; echo $$ARG > arg.txt; ./push_swap $$ARG | ./checker_Mac $$ARG

clean:
				${RM} ${OBJ} ${OBJB}
				make clean -C ${LIBFTDIR}

fclean: 	clean
				make fclean -C ${LIBFTDIR}
				${RM} ${NAME}

re: 		fclean all

rebonus:	fclean bonus

.PHONY:		all bonus clean fclean re rebonus
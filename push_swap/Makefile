# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 07:03:20 by dmontoro          #+#    #+#              #
#    Updated: 2023/07/11 21:33:24 by dmontoro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CC	= gcc

CFLAGS	= -g3 -O0 -D BUFFER_SIZE=42 -Wall -Werror -Wextra

RM	= rm -f

SRCS	= push_swap.c parse.c smallsort.c inst1.c inst2.c

OBJ	= ${SRCS:.c=.o}

LIBFT = libft

LIBFTDIR = ./libs/libft/

LIBFTNAME = libft.a

LIBFTPATH = ${LIBFTDIR}${LIBFTNAME}

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJ} ${LIBFTPATH}
				${CC} ${CFLAGS} ${OBJ} -L${LIBFTDIR} -l${LIBFT} -o ${NAME}

${LIBFTPATH}:
				@make bonus -C ${LIBFTDIR}


all:		${NAME}

bonus:		all ${OBJB}
				@make OBJ="${OBJB}"

stack: ${LIBFTPATH}
	$(CC) -o create_stack create_stack.c ${LIBFTPATH}
	./create_stack a.txt
	$(RM) create_stack

pswap:
	ARG=$$(cat a.txt); ./push_swap $$ARG | ./checker_Mac $$ARG

clean:
				${RM} ${OBJ} ${OBJB}
				make clean -C ${LIBFTDIR}

fclean: 	clean
				make fclean -C ${LIBFTDIR}
				${RM} ${NAME}

re: 		fclean all

rebonus:	fclean bonus

.PHONY:		all bonus clean fclean re rebonus
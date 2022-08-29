# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 07:03:20 by dmontoro          #+#    #+#              #
#    Updated: 2022/08/29 07:44:53 by dmontoro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

CC	= gcc

FLAGS	= -Wall -Werror -Wextra

RM	= rm -f

AR = ar -rcs

SRCS	= 	main.c parser.c parse_hexa.c parse_number.c parse_text.c parse_pointer.c

OBJ	= ${SRCS:.c=.o}

.c.o:
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJ}
				${AR} ${NAME} ${OBJ}

all:		${NAME}

clean:
				${RM} ${OBJ}

fclean: 	clean
				${RM} ${NAME}

re: 		fclean all

.PHONY:		all clean fclean re
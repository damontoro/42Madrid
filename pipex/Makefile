# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 07:03:20 by dmontoro          #+#    #+#              #
#    Updated: 2023/06/15 20:15:11 by dmontoro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

CC	= gcc

CFLAGS	= -g3 -O0 -D BUFFER_SIZE=42 -Wall -Werror -Wextra #-fsanitize=address

RM	= rm -f

SRCS	= pipex.c pipexAux.c pipexAux2.c

OBJS	= ${SRCS:.c=.o}

LIBFT   =  ./libs/libft/libft.a

all:		${NAME}

.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -Iincludes $(LIBFT) -o $(NAME)

$(LIBFT):
	@make bonus -C ./libs/libft/

clean:
	@rm -rf $(OBJS)
	@echo "cleaning .o files"
	@make clean -C ./libs/libft/

fclean: clean
	@make fclean -C ./libs/libft/
	@rm -rf $(NAME)

re: 		fclean all

rebonus:	fclean bonus

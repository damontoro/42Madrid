# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 07:03:20 by dmontoro          #+#    #+#              #
#    Updated: 2023/07/12 13:51:56 by dmontoro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

CC	= gcc

CFLAGS	= -g3 -O0 -D BUFFER_SIZE=42 #-Wall -Werror -Wextra #-fsanitize=address

RM	= rm -f

SRCS	= pipex.c pipexAux.c pipexAux2.c pipexAux3.c #../leak_detector_c/leak_detector_c.c

OBJS	= ${SRCS:.c=.o}

BNS_SRCS	= pipex.c pipexAux.c pipexAux2.c pipexAux3.c

BNS_OBJS	= $(BNS_SRCS:.c=.o)

LIBFT   =  ./libs/libft/libft.a

BONUS = .

all:		${NAME}

bonus: ${BONUS}

.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -Iincludes $(LIBFT) -o $(NAME)

$(BONUS): $(BNS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(BNS_SRCS) -Iincludes $(LIBFT) -o $(NAME)

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

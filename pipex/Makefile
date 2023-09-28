# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 07:03:20 by dmontoro          #+#    #+#              #
#    Updated: 2023/09/28 19:06:07 by dmontoro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

CC	= gcc

CFLAGS	= -g3 -O0 -D BUFFER_SIZE=42 -Wall -Werror -Wextra #-fsanitize=address

RM	= rm -f

SRCS	= pipex.c pipexAux.c pipexAux2.c pipexAux3.c #../leak_detector_c/leak_detector_c.c

OBJS	= ${SRCS:.c=.o}

BNS_SRCS	= pipex_bonus.c pipexAux_bonus.c pipexAux2_bonus.c pipexAux3_bonus.c

BNS_OBJS	= $(BNS_SRCS:.c=.o)

LIBFT   =  ./libft/libft.a

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
	@make bonus -C ./libft/

clean:
	@rm -rf $(OBJS) $(BNS_OBJS)
	@echo "cleaning .o files"
	@make clean -C ./libft/

fclean: clean
	@make fclean -C ./libft/
	@rm -rf $(NAME)

re: 		fclean all

rebonus:	fclean bonus

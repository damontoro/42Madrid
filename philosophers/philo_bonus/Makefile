# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/23 10:54:46 by dmontoro          #+#    #+#              #
#    Updated: 2023/07/23 10:59:26 by dmontoro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

CC	= gcc

CFLAGS	= -g3 -O0 -Wall -Werror -Wextra #-fsanitize=address

RM	= rm -f

SRCS	= philo.c #../leak_detector_c/leak_detector_c.c

OBJS	= ${SRCS:.c=.o}

BNS_SRCS	= philo.c

BNS_OBJS	= $(BNS_SRCS:.c=.o)


BONUS = .

all:		${NAME}

bonus: ${BONUS}

.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(BONUS): $(BNS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(BNS_SRCS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@echo "cleaning .o files"

fclean: clean
	@rm -rf $(NAME)

re: 		fclean all

rebonus:	fclean bonus

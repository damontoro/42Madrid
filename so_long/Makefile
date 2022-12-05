# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 07:03:20 by dmontoro          #+#    #+#              #
#    Updated: 2022/12/05 12:40:35 by dmontoro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

CC	= gcc

CFLAGS	= -g -O0 -D BUFFER_SIZE=42 -Wall -Werror -Wextra -fsanitize=address

RM	= rm -f

SRCS	= so_long.c \
			algorithms.c auxFunctions2.c auxFunctions3.c auxFunctions4.c\
			mapParser.c auxFunctions.c \
			utils/get_next_line.c utils/get_next_line_utils.c utils/utils.c

BNS_SRCS	= bonus/so_long_bonus.c \
			bonus/algorithms_bonus.c bonus/auxFunctions2_bonus.c bonus/auxFunctions3_bonus.c bonus/auxFunctions4_bonus.c\
			bonus/mapParser_bonus.c bonus/auxFunctions_bonus.c \
			utils/get_next_line.c utils/get_next_line_utils.c utils/utils.c

BNS_OBJS	= $(BNS_SRCS:.c=.o)
OBJS    =   $(SRCS:.c=.o)
LIBFT   =   ./libs/libft/libft.a

BONUS = .

all: $(NAME)

bonus: ${BONUS}

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJS) $(INCL) $(LIBFT)
	$(CC) $(CFLAGS) $(SRCS) -Iincludes $(LIBFT) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(BONUS): $(BNS_OBJS) $(INCL) $(LIBFT)
	$(CC) $(CFLAGS) $(BNS_SRCS) -Iincludes $(LIBFT) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(LIBFT):
	@make bonus -C ./libs/libft/

$(MLX):
	@make -C ./mlx/

clean:
	@rm -rf $(OBJS)
	@rm -rf $(BNS_OBJS)
	@echo "cleaning .o files"
	@make clean -C ./libs/libft/

fclean: clean
	@make fclean -C ./libs/libft/
	@rm -rf $(NAME)

re: fclean all
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/02 09:54:29 by dmontoro          #+#    #+#              #
#    Updated: 2023/10/02 10:34:46 by dmontoro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                   PROGRAM                                    #
# **************************************************************************** #

NAME		= agenda

# **************************************************************************** #
#                                   COMPILER                                   #
# **************************************************************************** #

CC 			= g++

CFLAGS		=  -Wall -Wextra -Werror -O3 -std=c++98
RM			= rm -f

# **************************************************************************** #
#                                   SOURCES                                    #
# **************************************************************************** #

SRCS 		=	main.cpp Contact.cpp PhoneBook.cpp

OBJS	= ${SRCS:.cpp=.o}


# **************************************************************************** #
#                                    RULES                                     #
# **************************************************************************** #

all: $(NAME)

.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS)
	@echo "\n\033[32mCompiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"

clean:
	@$(RM) -rf $(OBJS)

fclean:		clean
	@$(RM) $(NAME)
	@echo "\n\033[31mDeleting EVERYTHING! ⌐(ಠ۾ಠ)¬\033[37m\n"

re:			fclean all

bonus:		re

.PHONY:		all clean fclean re bonus
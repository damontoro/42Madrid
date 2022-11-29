# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 07:03:20 by dmontoro          #+#    #+#              #
#    Updated: 2022/11/29 07:15:20 by dmontoro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

CC	= gcc

FLAGS	= -Wall -Werror -Wextra

RM	= rm -f

AR = ar -rcs

MANDATORY_SRCS	= 	ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c ft_split.c \
					ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
					ft_itoa.c ft_memcpy.c  ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c \
					ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c \
					ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c  ft_strrchr.c \
					ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c  \
					ft_putstr_fd.c  ft_strjoin.c ft_strmapi.c ft_strtrim.c	ft_striteri.c \
					ft_swap.c ft_strrev.c ft_isspace.c

MANDATORY_OBJ	= ${MANDATORY_SRCS:.c=.o}

BONUS_SRCS	= 		ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
					ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c \
					ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c

BONUS_OBJ	= ${BONUS_SRCS:.c=.o}

BONUS_RELINK = .

.c.o:
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${MANDATORY_OBJ}
				${AR} ${NAME} ${MANDATORY_OBJ}

all:		${NAME}

clean:
				${RM} ${MANDATORY_OBJ} ${BONUS_OBJ}

fclean: 	clean
				${RM} ${NAME}

re: 		fclean all

bonus: 	${BONUS_RELINK}

${BONUS_RELINK}:	${MANDATORY_OBJ} ${BONUS_OBJ}
						${AR} ${NAME} ${MANDATORY_OBJ} ${BONUS_OBJ}
				
rebonus:	fclean bonus

so:
	$(CC) -nostartfiles -fPIC $(FLAGS) $(MANDATORY_SRCS)
	gcc -nostartfiles -shared -o libft.so $(MANDATORY_OBJ)

.PHONY:		all clean fclean re bonus rebonus
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 07:03:20 by dmontoro          #+#    #+#              #
#    Updated: 2022/08/29 11:15:47 by dmontoro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

LIBFT	= libft.a

CC	= gcc

FLAGS	= -Wall -Werror -Wextra

RM	= rm -f

AR = ar -rcs

SRCS	= ft_printf.c parser.c parse_hexa.c parse_number.c parse_text.c parse_pointer.c utils.c \
					libft/ft_isalnum.c libft/ft_isprint.c libft/ft_memcmp.c libft/ft_putchar_fd.c libft/ft_split.c \
					libft/ft_strlcat.c libft/ft_strncmp.c libft/ft_substr.c libft/ft_atoi.c libft/ft_isalpha.c \
					libft/ft_itoa.c libft/ft_memcpy.c  libft/ft_putendl_fd.c libft/ft_strchr.c  libft/ft_strlcpy.c \
					libft/ft_strnstr.c libft/ft_tolower.c libft/ft_bzero.c   libft/ft_isascii.c \
					libft/ft_memmove.c libft/ft_putnbr_fd.c  libft/ft_strdup.c  libft/ft_strlen.c  libft/ft_strrchr.c \
					libft/ft_toupper.c libft/ft_calloc.c  libft/ft_isdigit.c libft/ft_memchr.c  libft/ft_memset.c  \
					libft/ft_putstr_fd.c  libft/ft_strjoin.c libft/ft_strmapi.c libft/ft_strtrim.c	libft/ft_striteri.c \
					libft/ft_swap.c libft/ft_strrev.c libft/ft_isspace.c \
					libft/ft_lstadd_back_bonus.c libft/ft_lstadd_front_bonus.c libft/ft_lstclear_bonus.c \
					libft/ft_lstdelone_bonus.c libft/ft_lstiter_bonus.c libft/ft_lstlast_bonus.c \
					libft/ft_lstmap_bonus.c libft/ft_lstnew_bonus.c libft/ft_lstsize_bonus.c
			
OBJ	= ${SRCS:.c=.o}

LIBFT_SRCS	=		libft/ft_isalnum.c libft/ft_isprint.c libft/ft_memcmp.c libft/ft_putchar_fd.c libft/ft_split.c \
					libft/ft_strlcat.c libft/ft_strncmp.c libft/ft_substr.c libft/ft_atoi.c libft/ft_isalpha.c \
					libft/ft_itoa.c libft/ft_memcpy.c  libft/ft_putendl_fd.c libft/ft_strchr.c  libft/ft_strlcpy.c \
					libft/ft_strnstr.c libft/ft_tolower.c libft/ft_bzero.c   libft/ft_isascii.c \
					libft/ft_memmove.c libft/ft_putnbr_fd.c  libft/ft_strdup.c  libft/ft_strlen.c  libft/ft_strrchr.c \
					libft/ft_toupper.c libft/ft_calloc.c  libft/ft_isdigit.c libft/ft_memchr.c  libft/ft_memset.c  \
					libft/ft_putstr_fd.c  libft/ft_strjoin.c libft/ft_strmapi.c libft/ft_strtrim.c	libft/ft_striteri.c \
					libft/ft_swap.c libft/ft_strrev.c libft/ft_isspace.c \
					libft/ft_lstadd_back_bonus.c libft/ft_lstadd_front_bonus.c libft/ft_lstclear_bonus.c \
					libft/ft_lstdelone_bonus.c libft/ft_lstiter_bonus.c libft/ft_lstlast_bonus.c \
					libft/ft_lstmap_bonus.c libft/ft_lstnew_bonus.c libft/ft_lstsize_bonus.c

LIBFT_OBJS	= ${LIBFT_SRCS:.c=.o}


.c.o:
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJ}
				${AR} ${NAME} ${OBJ}
				
${LIBFT}:	${LIBFT_OBJS}
				${AR} ${NAME} ${LIBFT_OBJS}

all:		${NAME}

clean:
				${RM} ${OBJ}

fclean: 	clean
				${RM} ${NAME}

re: 		fclean all

.PHONY:		all clean fclean re
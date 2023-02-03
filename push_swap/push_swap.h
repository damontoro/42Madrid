#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <limits.h>
# include "libs/libft/libft.h"

typedef struct s_stack
{
	int size;
	t_list *top;
	t_list *bottom;
}					t_stack;

void	ft_error(char *str);
int		ft_err_atoi(const char *str);

# endif
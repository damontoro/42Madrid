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
void	parseArgs(t_stack *stack, int argc, char **argv);
int		sorted(t_list *list);

int		find_min_index(t_stack *stack, int *m);
int		find_max_index(t_stack *stack, int *m);
int		find_min(t_stack *stack, int *m);
int		find_max(t_stack *stack, int *m);
int		find_next_min(t_stack *stack, int m);
void	moveto_first(t_stack *stack, int pos, char c);

void	index_stack(t_stack *stack);
int		is_min_max(t_stack *a, t_stack *b);
void	insert_min_max(t_stack *a, t_stack *b);
void	insert_mid(t_stack *a, t_stack *b);

void	small_sort(t_stack *a, t_stack *b);
void	big_sort(t_stack *a, t_stack *b);

void	swap(t_stack *stack, char c);
void	ss(t_stack *a, t_stack *b);
void	push(t_stack *from, t_stack *to, char c);
void	rotate(t_stack *stack, char c);
void	rr(t_stack *a, t_stack *b);
void	rrotate(t_stack *stack, int c);
void	rrr(t_stack *a, t_stack *b);

# endif
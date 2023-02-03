#include "push_swap.h"

void ft_error(char *str)
{
	write(1, str, ft_strlen(str));
	exit(1);
}

void swap(struct s_stack *stack)
{
	t_list *tmp;
	t_list *tmp2;

	if (stack->size > 1)
	{
		tmp = stack->top;
		tmp2 = stack->top->next;
		stack->top = tmp2;
		tmp->next = tmp2->next;
		tmp2->next = tmp;
	}
}

void push(struct s_stack *from, struct s_stack *to)
{
	t_list *tmp;

	if (from->size > 0)
	{
		tmp = from->top;
		from->top = from->top->next;
		from->size--;
		if (to->size == 0)
		{
			to->top = tmp;
			to->bottom = tmp;
			tmp->next = NULL;
		}
		else
		{
			tmp->next = to->top;
			to->top = tmp;
		}
		to->size++;
	}
}

void rotate(struct s_stack *stack)
{
	t_list *tmp;
	t_list *tmp2;

	if(stack->size > 1)
	{
		tmp = stack->top;
		tmp2 = stack->top->next;
		stack->top = tmp2;
		stack->bottom->next = tmp;
		stack->bottom = tmp;
		stack->bottom->next = NULL;
	}
}

void rrotate(struct s_stack *stack)
{
	t_list *tmp;
	t_list *tmp2;

	if (stack->size > 1)
	{
		tmp = stack->top;
		while (tmp->next != stack->bottom)
			tmp = tmp->next;
		tmp2 = stack->bottom;
		stack->bottom = tmp;
		stack->bottom->next = NULL;
		tmp2->next = stack->top;
		stack->top = tmp2;
	}
}
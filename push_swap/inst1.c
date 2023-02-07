#include "push_swap.h"

void swap(t_stack *stack, char c)
{
	int tmp;

	if (stack->size > 1)
	{
		tmp = stack->top->content;
		stack->top->content = stack->top->next->content;
		stack->top->next->content = tmp;
		
	}
	if(c == 0)
		return ;
	ft_putchar_fd('s', 1);
	ft_putchar_fd(c, 1);
	ft_putchar_fd('\n', 1);
}

void ss(t_stack *a, t_stack *b)
{
	swap(a, 0);
	swap(b, 0);
	ft_putstr_fd("ss\n", 1);
}

void push(t_stack *from, t_stack *to, char c)
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
	if(c == 0)
		return ;
	ft_putchar_fd('p', 1);
	ft_putchar_fd(c, 1);
	ft_putchar_fd('\n', 1);
}

void rotate(t_stack *stack, char c)
{
	t_list *tmp;

	if(stack->size > 1)
	{
		tmp = stack->top;
		stack->top = tmp->next;
		stack->bottom->next = tmp;
		stack->bottom = tmp;
		stack->bottom->next = NULL;
	}
	if(c == 0)
		return ;
	ft_putchar_fd('r', 1);
	ft_putchar_fd(c, 1);
	ft_putchar_fd('\n', 1);
}

void rr(t_stack *a, t_stack *b)
{
	rotate(a, 0);
	rotate(b, 0);
	ft_putstr_fd("rr\n", 1);
}

void rrotate(t_stack *stack, int c)
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
	if(c == 0)
		return ;
	ft_putstr_fd("rr", 2);
	ft_putchar_fd(c, 1);
	ft_putchar_fd('\n', 1);
}

void rrr(t_stack *a, t_stack *b)
{
	rrotate(a, 0);
	rrotate(b, 0);
	ft_putstr_fd("rrr\n", 1);
}
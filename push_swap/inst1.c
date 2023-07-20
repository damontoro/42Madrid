/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 08:45:43 by dmontoro          #+#    #+#             */
/*   Updated: 2023/07/20 09:23:16 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_stack *stack, char c)
{
	int elem;
	int index;

	if (stack->size > 1)
	{
		elem = stack->top->content;
		index = stack->top->index;
		stack->top->content = stack->top->next->content;
		stack->top->index = stack->top->next->index;
		stack->top->next->content = elem;
		stack->top->next->index = index;
		
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
		if(from->top)
			from->top->prior = NULL;
		else
			from->bottom = NULL;
		from->size--;
		if (to->size == 0)
		{
			to->top = tmp;
			to->bottom = tmp;
			tmp->next = NULL;
			tmp->prior = NULL;
		}
		else
		{
			tmp->next = to->top;
			to->top->prior = tmp;
			to->top = tmp;
			tmp->prior = NULL;
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
		tmp->prior = stack->bottom;
		stack->bottom = tmp;
		stack->bottom->next = NULL;
		stack->top->prior = NULL;
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
	if (stack->size > 1)
	{
		stack->top->prior = stack->bottom;
		stack->bottom->next = stack->top;
		stack->bottom = stack->bottom->prior;
		stack->bottom->next = NULL;
		stack->top = stack->top->prior;
		stack->top->prior = NULL;
	}
	if(c == 0)
		return ;
	ft_putstr_fd("rr", 1);
	ft_putchar_fd(c, 1);
	ft_putchar_fd('\n', 1);
}

void rrr(t_stack *a, t_stack *b)
{
	rrotate(a, 0);
	rrotate(b, 0);
	ft_putstr_fd("rrr\n", 1);
}
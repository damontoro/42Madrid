/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:43:51 by dmontoro          #+#    #+#             */
/*   Updated: 2023/07/20 12:49:33 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"	

void static	swap_pointers(t_stack *to, t_list *tmp)
{
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
}

void	push(t_stack *from, t_stack *to, char c)
{
	t_list	*tmp;

	if (from->size > 0)
	{
		tmp = from->top;
		from->top = from->top->next;
		if (from->top)
			from->top->prior = NULL;
		else
			from->bottom = NULL;
		from->size--;
		swap_pointers(to, tmp);
		to->size++;
	}
	if (c == 0)
		return ;
	ft_putchar_fd('p', 1);
	ft_putchar_fd(c, 1);
	ft_putchar_fd('\n', 1);
}

void	swap(t_stack *stack, char c)
{
	int	elem;
	int	index;

	if (stack->size > 1)
	{
		elem = stack->top->content;
		index = stack->top->index;
		stack->top->content = stack->top->next->content;
		stack->top->index = stack->top->next->index;
		stack->top->next->content = elem;
		stack->top->next->index = index;
	}
	if (c == 0)
		return ;
	ft_putchar_fd('s', 1);
	ft_putchar_fd(c, 1);
	ft_putchar_fd('\n', 1);
}

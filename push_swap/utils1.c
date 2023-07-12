/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 06:57:21 by dmontoro          #+#    #+#             */
/*   Updated: 2023/07/12 09:31:14 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_min(t_stack *a, int *m)
{
	int min;
	int pos;
	int ret;
	t_list *tmp;

	pos = 0;
	ret = 0;
	tmp = a->top;
	min = tmp->content;
	while (tmp != NULL)
	{
		if (tmp->content < min){
			min = tmp->content;
			ret = pos;
		}
		pos++;
		tmp = tmp->next;
	}
	*m = min;
	return (ret);
}

int find_max(t_stack *a, int *m)
{
	int max;
	int pos;
	int ret;
	t_list *tmp;

	pos = 0;
	tmp = a->top;
	max = tmp->content;
	while (tmp != NULL)
	{
		if (tmp->content > max){
			max = tmp->content;
			ret = pos;
		}
		pos++;
		tmp = tmp->next;
	}
	*m = max;
	return (ret);
}

//this returns the minimum number that is greater than the given min
int find_next_min(t_stack *a, int min)
{
	int ret;
	t_list *tmp;

	tmp = a->top;
	find_max(a, &ret);
	while (tmp != NULL)
	{
		if (tmp->content > min && tmp->content < ret){
			ret = tmp->content;
		}
		tmp = tmp->next;
	}
	return (ret);
}

void	moveto_first(t_stack *a, int pos)
{
	int i;

	i = 0;
	if (pos <= ft_lstsize(a->top) / 2)
	{
		while (i < pos)
		{
			rotate(a, 'a');
			i++;
		}
	}
	else
	{
		while (i < ft_lstsize(a->top) - pos)
		{
			rrotate(a, 'a');
			i++;
		}
	}
}

void index_stack(t_stack *stack)
{
	t_list *tmp;
	int i;
	int min;

	i = 0;
	find_min(stack, &min);
	while(i < ft_lstsize(stack->top))
	{
		tmp = stack->top;
		while(tmp->content != min)
			tmp = tmp->next;
		tmp->index = i;
		min = find_next_min(stack, min);
		i++;
	}
	
}

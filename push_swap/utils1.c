/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 06:57:21 by dmontoro          #+#    #+#             */
/*   Updated: 2023/07/12 07:08:33 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_min(t_stack *a)
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
	return (ret);
}

int find_max(t_stack *a)
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
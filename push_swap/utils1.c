/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 06:57:21 by dmontoro          #+#    #+#             */
/*   Updated: 2023/07/20 10:02:42 by dmontoro         ###   ########.fr       */
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

int find_min_index(t_stack *a, int *m)
{
	int min;
	int pos;
	int ret;
	t_list *tmp;

	pos = 0;
	ret = 0;
	tmp = a->top;
	min = tmp->index;
	while (tmp != NULL)
	{
		if (tmp->index < min){
			min = tmp->index;
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

int find_max_index(t_stack *a, int *m)
{
	int max;
	int pos;
	int ret;
	t_list *tmp;

	pos = 0;
	tmp = a->top;
	max = tmp->index;
	while (tmp != NULL)
	{
		if (tmp->index > max)
		{
			max = tmp->index;
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inserts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 07:10:13 by dmontoro          #+#    #+#             */
/*   Updated: 2023/07/20 12:40:24 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_bigger(t_stack *a, int elem)
{
	int		ret;
	t_list	*tmp;
	int		pos;

	pos = 0;
	ret = INT_MAX;
	tmp = a->top;
	while (tmp != NULL)
	{
		if (tmp->index > elem && tmp->index < ret)
			ret = pos;
		tmp = tmp->next;
		pos++;
	}
	return (ret);
}

int	is_min_max(t_stack *a, t_stack *b)
{
	int	min;
	int	max;

	if (b->size == 0)
		return (1);
	find_min_index(b, &min);
	find_max_index(b, &max);
	if (a->top->index < min || a->top->index > max)
		return (1);
	return (0);
}

void	insert_min_max(t_stack *a, t_stack *b)
{
	int	min;
	int	pos_min;

	if (b->size == 0)
		push(a, b, 'b');
	else
	{
		pos_min = find_min_index(b, &min);
		moveto_first(b, pos_min, 'b');
		push(a, b, 'b');
	}
}

void	insert_mid(t_stack *a, t_stack *b)
{
	int	pos_bigger;

	pos_bigger = find_bigger(b, a->top->index);
	moveto_first(b, pos_bigger, 'b');
	push(a, b, 'b');
}

//Moves the element in the position pos to the top of the stack
void	moveto_first(t_stack *a, int pos, char c)
{
	int	i;

	i = 0;
	if (pos <= a->size / 2)
	{
		while (i < pos)
		{
			rotate(a, c);
			i++;
		}
	}
	else
	{
		while (i < a->size - pos)
		{
			rrotate(a, c);
			i++;
		}
	}
}

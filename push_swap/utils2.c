/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:34:04 by dmontoro          #+#    #+#             */
/*   Updated: 2023/07/20 13:21:05 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int static	find_top(t_stack *a, int chunk, int chunk_size)
{
	t_list	*tmp;
	int		pos;

	pos = 0;
	tmp = a->top;
	while (tmp != NULL)
	{
		if (tmp->index >= chunk * chunk_size && tmp->index \
			< (chunk + 1) * chunk_size)
			return (pos);
		pos++;
		tmp = tmp->next;
	}
	return (-1);
}

static int	find_bottom(t_stack *a, int chunk, int chunk_size)
{
	t_list	*tmp;
	int		pos;

	pos = 0;
	tmp = a->bottom;
	while (tmp != NULL)
	{
		if (tmp->index >= chunk * chunk_size && tmp->index \
			< (chunk + 1) * chunk_size)
			return (a->size - pos - 1);
		pos++;
		tmp = tmp->prior;
	}
	return (-1);
}

int	find_num(t_stack *a, int chunk, int chunk_size, int mode)
{
	int		pos;

	if (mode == 0)
		pos = find_top(a, chunk, chunk_size);
	else if (mode == 1)
		pos = find_bottom(a, chunk, chunk_size);
	else
		pos = -1;
	return (pos);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 08:51:02 by dmontoro          #+#    #+#             */
/*   Updated: 2023/07/22 09:55:42 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	num_in_chunk(t_stack *a, int chunk, int chunk_size)
{
	t_list	*tmp;

	tmp = a->top;
	while (tmp != NULL)
	{
		if (tmp->index >= chunk * chunk_size && tmp->index \
			< (chunk + 1) * chunk_size)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static void	move_best_top(t_stack *a, int pos_up, int pos_down, char c)
{
	int	mov_up;
	int	mov_down;

	if (pos_up <= a->size / 2)
		mov_up = pos_up;
	else
		mov_up = a->size - pos_up;
	if (pos_down <= a->size / 2)
		mov_down = pos_down;
	else
		mov_down = a->size - pos_down;
	if (mov_up <= mov_down)
		moveto_first(a, pos_up, c);
	else
		moveto_first(a, pos_down, c);
}

void	move_b_to_a(t_stack *a, t_stack *b, int up, int down)
	{
	while (b->size > 0)
	{
		up = find_max(b, &down);
		moveto_first(b, up, 'b');
		push(b, a, 'a');
	}
}

void	big_sort(t_stack *a, t_stack *b)
{
	int	chunk_size;
	int	current_chunk;
	int	up;
	int	down;

	if (a->size <= 100)
		chunk_size = a->size / 5;
	else if (a->size <= 500)
		chunk_size = a->size / 11;
	else
		chunk_size = a->size / 20;
	current_chunk = 0;
	while (a->size > 0)
	{
		up = find_num(a, current_chunk, chunk_size, 0);
		down = find_num(a, current_chunk, chunk_size, 1);
		move_best_top(a, up, down, 'a');
		if (is_min_max(a, b) == 1)
			insert_min_max(a, b);
		else
			insert_mid(a, b);
		if (!num_in_chunk(a, current_chunk, chunk_size))
			current_chunk++;
	}
	move_b_to_a(a, b, up, down);
}

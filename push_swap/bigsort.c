/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 08:51:02 by dmontoro          #+#    #+#             */
/*   Updated: 2023/07/20 11:01:38 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_num(t_stack *a, int chunk, int chunk_size, int mode){

	t_list *tmp;
	int pos;

	pos = 0;
	if(mode == 0){
		tmp = a->top;
		while(tmp != NULL){
			if(tmp->index >= chunk * chunk_size && tmp->index < (chunk + 1) * chunk_size)
				return (pos);
			pos++;
			tmp = tmp->next;
		}
	}
	else if(mode == 1){
		tmp = a->bottom;
		while(tmp != NULL){
			if(tmp->index >= chunk * chunk_size && tmp->index < (chunk + 1) * chunk_size)
				return (a->size - pos - 1);
			pos++;
			tmp = tmp->prior;
		}
	}
	return (-1);
}

static int	num_in_chunk(t_stack *a, int chunk, int chunk_size)
{
	t_list *tmp;

	tmp = a->top;
	while(tmp != NULL)
	{
		if(tmp->index >= chunk * chunk_size && tmp->index < (chunk + 1) * chunk_size)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static void	move_best_top(t_stack *a, int pos_up, int pos_down, char c)
{
	//check which pos would take less movements to get to the top
	int mov_up;
	int mov_down;

	if(pos_up <= a->size / 2)
		mov_up = pos_up;
	else
		mov_up = a->size - pos_up;
	if(pos_down <= a->size / 2)
		mov_down = pos_down;
	else
		mov_down = a->size - pos_down;

	if(mov_up <= mov_down)
		moveto_first(a, pos_up, c);
	else
		moveto_first(a, pos_down, c);
}

void big_sort(t_stack *a, t_stack *b)
{
	int chunk_size;
	int current_chunk;
	int up;
	int down;
	
	if(a->size <= 100)	
		chunk_size = a->size / 5;
	else if(a->size <= 500)
		chunk_size = a->size / 15;

	current_chunk = 0;
	while(a->size > 0)
	{
		//devuelve la posicion del primer numero del chunk por arriba
		up = find_num(a, current_chunk, chunk_size, 0);
		down = find_num(a, current_chunk, chunk_size, 1); //de segundo numero del chunk por abajo
		move_best_top(a, up, down, 'a');
		if(is_min_max(a, b) == 1)
			insert_min_max(a, b);
		else
			insert_mid(a, b);
		if(!num_in_chunk(a, current_chunk, chunk_size))
			current_chunk++;
	}
	while(b->size > 0)
	{
		up = find_max(b, &down);
		moveto_first(b, up, 'b');
		push(b, a, 'a');
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 08:51:02 by dmontoro          #+#    #+#             */
/*   Updated: 2023/07/12 09:37:05 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//devuelve la posición del numero
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

void big_sort(t_stack *a, t_stack *b)
{
	int chunk_size;
	int current_chunk;
	int up;
	int down;

	(void)b;
	
	if(a->size <= 100)	
		chunk_size = a->size / 5;
	else if(a->size <= 500)
		chunk_size = a->size / 11;

	current_chunk = 0;
	while(a->size > 0)
	{
		//devuelve la posicion del primer numero del chunk por arriba
		up = find_num(a, current_chunk, chunk_size, 0);
		down = find_num(a, current_chunk, chunk_size, 1); //de segundo numero del chunk por abajo
	}

}
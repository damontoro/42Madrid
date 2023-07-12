/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 08:28:20 by dmontoro          #+#    #+#             */
/*   Updated: 2023/07/12 09:16:58 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	//t_list *tmp;


	stack_a = (t_stack *)calloc(1, (sizeof(t_stack)));
	stack_b = (t_stack *)calloc(1, (sizeof(t_stack)));
	if(argc <= 1)
		exit(0);

	parseArgs(stack_a, argc, argv);
	index_stack(stack_a);
	if (!sorted(stack_a->top))
	{
		if (ft_lstsize(stack_a->top) <= 5)
			small_sort(stack_a, stack_b);
		else
			big_sort(stack_a, stack_b);
	}
	// tmp = stack_a->top;
	// while(tmp != NULL){
	// 	printf("%d\n", tmp->content);
	// 	tmp = tmp->next;
	// }
	ft_lstclear(&stack_a->top);
	free(stack_a);
	ft_lstclear(&stack_b->top);
	free(stack_b);
	return (0);
}
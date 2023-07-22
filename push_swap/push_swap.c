/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 08:28:20 by dmontoro          #+#    #+#             */
/*   Updated: 2023/07/22 09:19:33 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void ex(){
// 	system("leaks push_swap");
// }

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = (t_stack *)ft_calloc(1, (sizeof(t_stack)));
	stack_b = (t_stack *)ft_calloc(1, (sizeof(t_stack)));
	if (argc <= 1)
		ft_error("Error\n");
	parse_args(stack_a, argc, argv);
	index_stack(stack_a);
	if (!sorted(stack_a->top))
	{
		if (ft_lstsize(stack_a->top) <= 5)
			small_sort(stack_a, stack_b);
		else
			big_sort(stack_a, stack_b);
	}
	ft_lstclear(&stack_a->top);
	ft_lstclear(&stack_b->top);
	free(stack_a);
	free(stack_b);
	return (0);
}

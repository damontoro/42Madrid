#include "push_swap.h"

void	sort3(t_stack *a)
{
	
}

void	smallSort(t_stack *a, t_stack *b)
{
	if (ft_lstsize(a->top) == 2)
		rotate(a, 'a');
	else if (ft_lstsize(a->top) == 3)
		sort3(a);
	/*
	else if (ft_lstsize(a->top) == 4)
		sort4(a, b);
	else if (ft_lstsize(a->top) == 5)
		sort5(a, b);
	*/
}
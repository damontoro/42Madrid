#include "push_swap.h"


void	sort3(t_stack *a)
{
	int first;
	int second;
	int third;

	first = a->top->content;
	second = a->top->next->content;
	third = a->top->next->next->content;
	if(first > second && second < third && third > first)//
		swap(a, 'a');
	else if(first > second && second > third && third < first)
	{
		swap(a, 'a');
		rrotate(a, 'a');
	}
	else if(first > second && second < third && third < first)//
		rotate(a, 'a');
	else if(first < second && second > third && third > first)
	{
		swap(a, 'a');
		rotate(a, 'a');
	}
	else if(first < second && second > third && third < first)
		rrotate(a, 'a');
	
}

void sort5(t_stack *a, t_stack *b, int i)
{
	int min;

	while (i < 2)
	{
		min = find_min(a);
		moveto_first(a, min);
		push(a, b, 'b');
		i++;
	}
	sort3(a);
	push(b, a, 'a');
	push(b, a, 'a');
}

void	smallSort(t_stack *a, t_stack *b)
{
	if (ft_lstsize(a->top) == 2)
		rotate(a, 'a');
	else if (ft_lstsize(a->top) == 3)
		sort3(a);
	else if (ft_lstsize(a->top) == 4)
		sort5(a, b, 1);
	else if (ft_lstsize(a->top) == 5)
		sort5(a, b, 0);
}
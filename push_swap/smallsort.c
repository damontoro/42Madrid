#include "push_swap.h"

int findMin(t_stack *a)
{
	int min;
	t_list *tmp;

	tmp = a->top;
	min = tmp->content;
	while (tmp != NULL)
	{
		if (tmp->content < min)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

int findMax(t_stack *a)
{
	int max;
	t_list *tmp;

	tmp = a->top;
	max = tmp->content;
	while (tmp != NULL)
	{
		if (tmp->content > max)
			max = tmp->content;
		tmp = tmp->next;
	}
	return (max);
}

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

void sort5(t_stack *a, t_stack *b)
{
	int i;
	int min;
	int max;

	i = 0;
	while (i < 2)
	{
		min = findMin(a);
		max = findMax(a);
		if (a->top->content == min || a->top->content == max)
			push(a, b, 'b');
		else
			rotate(a, 'a');
		i++;
	}
	sort3(a);
	if (b->top->content > b->top->next->content)
		swap(b, 'b');
	push(b, a, 'a');
	push(b, a, 'a');
}

void	smallSort(t_stack *a, t_stack *b)
{
	if (ft_lstsize(a->top) == 2)
		rotate(a, 'a');
	else if (ft_lstsize(a->top) == 3)
		sort3(a);
	else if (ft_lstsize(a->top) == 5)
		sort5(a, b);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 08:11:15 by dmontoro          #+#    #+#             */
/*   Updated: 2023/07/20 13:18:04 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split(char **strs)
{
	int	i;

	i = 0;
	while (strs[i] != NULL)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

static void	search_repetition(t_list *top, int num)
{
	t_list	*tmp;

	tmp = top;
	while (tmp != NULL)
	{
		if (tmp->content == num)
			ft_error("Error\n");
		tmp = tmp->next;
	}
}

static void	assign_bottom(t_stack *stack)
{
	t_list	*tmp;

	if (stack->top != NULL)
	{
		tmp = stack->top;
		while (tmp->next != NULL)
			tmp = tmp->next;
		stack->bottom = tmp;
	}
}

void	parse_args(t_stack *stack, int argc, char **argv)
{
	int		i;
	int		j;
	char	**strs;
	int		num;

	i = 1;
	while (i < argc)
	{
		j = 0;
		strs = ft_split(argv[i], ' ');
		while (strs[j] != NULL)
		{	
			num = ft_err_atoi(strs[j]);
			search_repetition(stack->top, num);
			ft_lstadd_back(&stack->top, ft_lstnew(&num));
			stack->size++;
			j++;
		}
		free_split(strs);
		i++;
	}
	assign_bottom(stack);
}

int	sorted(t_list *top)
{
	t_list	*tmp;

	if (top == NULL)
		return (1);
	tmp = top;
	while (tmp->next != NULL)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

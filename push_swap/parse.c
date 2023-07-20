/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 08:11:15 by dmontoro          #+#    #+#             */
/*   Updated: 2023/07/20 10:59:04 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void freeSplit(char **strs){
	int i;

	i = 0;
	while(strs[i] != NULL){
		free(strs[i]);
		i++;
	}
	free(strs);
}

static void searchRepetition(t_list *top, int num){
	t_list *tmp;

	tmp = top;
	while(tmp != NULL){
		if(tmp->content == num)
			ft_error("Error\n");
		tmp = tmp->next;
	}
}

void parseArgs(t_stack *stack, int argc, char **argv){
	int		i;
	int		j;
	char	**strs;
	int		num;
	t_list	*tmp;

	i = 1;
	while(i < argc)
	{
		j = 0;
		strs = ft_split(argv[i], ' ');
		while (strs[j] != NULL)
		{	
			num = ft_err_atoi(strs[j]);
			searchRepetition(stack->top, num);
			ft_lstadd_back(&stack->top, ft_lstnew(&num));
			stack->size++;
			j++;
		}
		freeSplit(strs);
		i++;
	}
	if (stack->top != NULL)
	{
		tmp = stack->top;
		while (tmp->next != NULL)
			tmp = tmp->next;
		stack->bottom = tmp;
	}
}

int	sorted(t_list *top)
{
	t_list *tmp;

	if(top == NULL)
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
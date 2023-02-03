#include "push_swap.h"


//Debe petar si entra un numero repetido o algo que no es un numero

void freeSplit(char **strs){
	int i;

	i = 0;
	while(strs[i] != NULL){
		free(strs[i]);
		i++;
	}
	free(strs);
}

void searchRepetition(t_list *top, int *num){
	t_list *tmp;

	tmp = top;
	while(tmp != NULL){
		if(*(int *)tmp->content == *num)
			ft_error("Hay un numero repetido\n");
		tmp = tmp->next;
	}
}

void parseArgs(t_stack *stack, int argc, char **argv){
	int i;
	int j;
	char **strs;
	int *num;

	i = 1;
	while(i < argc){
		j = 0;
		strs = ft_split(argv[i], ' ');
		while (strs[j] != NULL)
		{	
			num = (int *)malloc(sizeof(int)); //primera alocacion, la referencia a esta memoria estará en el nodo
			*num = ft_err_atoi(strs[j]);
			searchRepetition(stack->top, num);
			ft_lstadd_back(&stack->top, ft_lstnew(num)); //segunda alocacion, creo el nodo, la referencia al nodo estará en la lista
			stack->size++;
			j++;
		}
		freeSplit(strs);
		i++;
	}
}

void readData(){}

int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	t_list *tmp;

	stack_a = (t_stack *)calloc(1, (sizeof(t_stack)));
	stack_b = (t_stack *)calloc(1, (sizeof(t_stack)));
	if(argc < 2)
		readData(stack_a);
	else
		parseArgs(stack_a, argc, argv);

	tmp = stack_a->top;
	while(tmp != NULL){
		printf("%d\n", *(int *)tmp->content);
		tmp = tmp->next;
	}
	ft_lstclear(&stack_a->top, free);
	free(stack_a);
	ft_lstclear(&stack_b->top, free);
	free(stack_b);
	return (0);
}
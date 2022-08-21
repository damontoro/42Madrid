#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "santi/parser.h"

int ft_printf(char const *s, ...){

	va_list list;
	int		i;

	i = 0;
	va_start(list, s);
	while (s[i])
	{
		if(s[i] != '%')
			write(1, &s[i], sizeof(char));
		else
			parse_var(s[++i], list);
		++i;
	}
	va_end(list);

	return (0);
}

int main(){

	ft_printf("H%cla", 'o');


	return 0;
}
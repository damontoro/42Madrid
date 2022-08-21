#include "printf.h"

int	parse_var(const char c, va_list list){

	int	(*function_list[FUN_NMB])(char, va_list);
	int	i;
	int res;
	int size;

	res = -1;
	function_list[0] = &parse_char;
	function_list[1] = &parse_string;
	i = 0;
	while (i < FUN_NMB && res == -1)
	{
		res = (*function_list[i])(c, list);
	}
	if (res == 0)
		return 0; //ha petado dentro del parse
	if (res == -1)
		return -1; //no ha encontrado parse

	return 0;
}


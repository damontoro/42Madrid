#include"printf.h"

int	parse_hexa(const char c, va_list list)
{
	char	*arg;

	if(c != 'X' && c != 'x')
		return -1;
	
	arg = va_arg(list, char *);
	ft_putstr_fd(arg, 1);
	return (1);
}

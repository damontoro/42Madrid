#include "printf.h"

int	parse_int(const char c, va_list list)
{
	int	arg;

	if(c != 'i')
		return -1;
	arg = va_arg(list, int);
	ft_putnbr_fd(arg, 1);
	return (1);
}
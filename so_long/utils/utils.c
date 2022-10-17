#include "utils.h"

void	ft_error(const char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}
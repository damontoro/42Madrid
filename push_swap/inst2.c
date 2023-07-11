#include "push_swap.h"

void ft_error(char *str)
{
	write(1, str, ft_strlen(str));
	exit(1);
}

static unsigned long long int	bad_numbers(unsigned long long int z, int y)
{
	unsigned long long int	bad_number;

	bad_number = INT_MAX;
	if ((z > bad_number + 1 && y < 0) || (z > bad_number && y > 0))
		ft_error("Int demasiado grande\n");
	return (z);
}

int	ft_err_atoi(const char *str)
{
	int						i;
	int						sign;
	unsigned long long int	num;

	num = 0;
	i = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (str[i] - '0') + (num * 10);
		i++;
	}
	if(str[i] != '\0')
		ft_error("El argumento no es un numero válido\n");
	num = bad_numbers(num, sign);
	return (num * sign);
}


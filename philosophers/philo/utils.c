/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:42:23 by dmontoro          #+#    #+#             */
/*   Updated: 2023/07/23 11:42:32 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}

static unsigned long long int	bad_numbers(unsigned long long int z, int y)
{
	unsigned long long int	bad_number;

	bad_number = INT_MAX;
	if ((z > bad_number + 1 && y < 0) || (z > bad_number && y > 0))
		ft_error("Error\n");
	return (z);
}

static void	manage_sign(int *sign, int *i, const char *str)
{
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			*sign = -(*sign);
		(*i)++;
	}
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
	manage_sign(&sign, &i, str);
	if (str[i] == '\0')
		ft_error("Error\n");
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (str[i] - '0') + (num * 10);
		i++;
	}
	if (str[i] != '\0')
		ft_error("Error\n");
	num = bad_numbers(num, sign);
	return (num * sign);
}
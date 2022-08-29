/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 12:01:34 by dmontoro          #+#    #+#             */
/*   Updated: 2022/08/21 16:41:52 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long long int	bad_numbers(unsigned long long int z, int y)
{
	unsigned long long int	bad_number;

	bad_number = 9223372036854775806;
	if (z > bad_number + 1 && y < 0)
		return (0);
	if (z > bad_number && y > 0)
		return (-1);
	return (z);
}

int	ft_atoi(const char *str)
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
	num = bad_numbers(num, sign);
	return (num * sign);
}

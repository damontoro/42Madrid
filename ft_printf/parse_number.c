/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 20:58:34 by dmontoro          #+#    #+#             */
/*   Updated: 2022/08/30 18:38:53 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	digits(long long int n)
{
	int	i;

	i = 1;
	while (n > 9)
	{
		n = n / 10;
		++i;
	}
	return (i);
}

int	parse_int(const char c, va_list list)
{
	int				arg;
	int				sign;
	long long int	ret;

	if (c != 'i' && c != 'd')
		return (-1);
	sign = 0;
	arg = va_arg(list, int);
	ret = arg;
	if (arg < 0)
	{
		sign = 1;
		ret = -ret;
	}
	ft_putnbr_fd(arg, 1);
	return (digits(ret) + sign);
}

int	parse_uint(const char c, va_list list)
{
	unsigned long int	arg;

	if (c != 'u')
		return (-1);
	arg = va_arg(list, unsigned int);
	ft_putunbr_fd(arg, 1);
	return (digits(arg));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 20:58:34 by dmontoro          #+#    #+#             */
/*   Updated: 2022/08/29 11:04:49 by dmontoro         ###   ########.fr       */
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
	int	arg;
	int	sign;

	if(c != 'i' && c != 'd')
		return -1;
	sign = 0;
	arg = va_arg(list, int);
	if (arg < 0)
		sign = 1;
	ft_putnbr_fd(arg, 1);
	return (digits(arg) + sign);
}

int	parse_uint(const char c, va_list list)
{
	unsigned int	arg;

	if(c != 'u')
		return -1;
	arg = va_arg(list, unsigned int);
	ft_putunbr_fd(arg, 1);
	return (digits(arg));
}

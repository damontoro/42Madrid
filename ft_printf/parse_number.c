/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 20:58:34 by dmontoro          #+#    #+#             */
/*   Updated: 2022/08/29 09:14:36 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	digits(long long int n)
{
	int	i;

	i = 1;
	while (n >= 10)
	{
		n = n / 10;
		++i;
	}
	return (i);
}

int	parse_int(const char c, va_list list)
{
	int	arg;

	if(c != 'i' && c != 'd')
		return -1;
	arg = va_arg(list, int);
	ft_putnbr_fd(arg, 1);
	return (1);
}

int	parse_uint(const char c, va_list list)
{
	unsigned int	arg;

	if(c != 'u')
		return -1;
	arg = va_arg(list, unsigned int);
	ft_putunbr_fd(arg, 1);
	return (1);
}

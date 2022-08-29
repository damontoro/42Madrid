/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 20:58:34 by dmontoro          #+#    #+#             */
/*   Updated: 2022/08/29 07:39:06 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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
	int	arg;

	if(c != 'u')
		return -1;
	arg = va_arg(list, unsigned int);
	ft_putnbr_fd(arg, 1);
	return (1);
}

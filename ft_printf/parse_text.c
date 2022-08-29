/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 20:58:31 by dmontoro          #+#    #+#             */
/*   Updated: 2022/08/29 11:05:03 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_char(const char c, va_list list)
{
	char	arg;

	if(c != 'c')
		return -1;
	arg = va_arg(list, int);
	ft_putchar_fd(arg, 1);
	return (1);
}

int	parse_string(const char c, va_list list)
{
	char	*arg;

	if(c != 's')
		return -1;
	arg = va_arg(list, char *);
	if (!arg)
		arg = "(null)";
	ft_putstr_fd(arg, 1);
	return (ft_strlen(arg));
}

int	parse_per(const char c, va_list list)
{
	char	arg;
	(void) list;

	arg = '%';
	if(c != '%')
		return -1;
	write(1, &arg, sizeof(char));
	return (1);
}

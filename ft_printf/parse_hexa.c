/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 20:58:37 by dmontoro          #+#    #+#             */
/*   Updated: 2022/08/21 21:04:40 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"printf.h"

char	*ft_itoh(int num)
{
	char	*buffer;
	char	*ret;
	
	buffer = "123456789ABCDEFGH";
	
}

int	parse_hexa(const char c, va_list list)
{
	int	arg;
	char *write;

	if(c != 'X' && c != 'x')
		return -1;
	arg = va_arg(list, int);
	write = ft_itoh(arg);
	ft_putstr_fd(arg, 1);
	return (1);
}

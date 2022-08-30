/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 20:58:37 by dmontoro          #+#    #+#             */
/*   Updated: 2022/08/30 18:38:11 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static void	ft_strtoupper(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		++i;
	}
}

int	parse_hexa(const char c, va_list list)
{
	int		arg;
	char	*write;
	int		size;

	if (c != 'X' && c != 'x')
		return (-1);
	arg = va_arg(list, int);
	write = ft_itoh(arg);
	if (c == 'X')
		ft_strtoupper(write);
	ft_strrev(write);
	size = ft_strlen(write);
	ft_putstr_fd(write, 1);
	free(write);
	return (size);
}

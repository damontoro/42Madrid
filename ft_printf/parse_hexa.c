/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 20:58:37 by dmontoro          #+#    #+#             */
/*   Updated: 2022/08/29 12:00:33 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	digs(int num)
{
	int	i;

	i = 1;
	while (num >= 16)
	{
		i++;
		num /= 16;
	}
	return (i);
}

char	*ft_itoh(unsigned int num)
{
	char					*ret;
	int						i;
	int						sign;
	unsigned long long int	aux;

	aux = num;
	sign = 0;
	if (aux < 0)
	{
		aux = -aux;
		sign = 1;
	}
	ret = malloc(sizeof(char) * (digs(aux) + sign + 1));
	i = 0;
	while (aux >= 16)
	{
		ret[i] = "0123456789abcdef"[aux % 16];
		++i;
		aux = aux / 16;
	}
	ret[i++] = "123456789abcdef"[aux - 1];
	ret[i] = '\0';
	return (ret);
}

void	ft_strtoupper(char *str)
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


	if(c != 'X' && c != 'x')
		return -1;
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 07:27:13 by dmontoro          #+#    #+#             */
/*   Updated: 2022/08/29 11:24:26 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

char	*ft_uitoh(unsigned long int num)
{
	char	*ret;
	int		i;

	i = 1;
	while (num >= 16)
	{
		i++;
		num /= 16;
	}
	ret = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (num >= 16)
	{
		ret[i] = "123456789abcdef"[num % 16 - 1];
		++i;
		num = num / 16;
	}
	ret[i++] = "123456789abcdef"[num - 1];
	ret[i] = '\0';
	return (ret);
}

int	parse_pointer(const char c, va_list list)
{
	unsigned long int	arg;
	char 				*write;
	int					size;

	if(c != 'p')
		return -1;
	arg = (unsigned long int)va_arg(list, void *);
	write = ft_uitoh(arg);
	size = ft_strlen(write);
	ft_putstr_fd(write, 1);
	free(write);
	return (size);
}

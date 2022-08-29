/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 20:58:20 by dmontoro          #+#    #+#             */
/*   Updated: 2022/08/29 09:12:49 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"printf.h"

int	ft_printf(char const *s, ...)
{
	va_list	list;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	va_start(list, s);
	while (s[i])
	{
		if (s[i] != '%')
		{
			write(1, &s[i], sizeof(char));
			++ret;
		}
		else
			ret += parse_var(s[++i], list);
		++i;
	}
	va_end(list);
	return (ret);
}

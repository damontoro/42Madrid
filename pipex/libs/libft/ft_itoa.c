/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 12:46:05 by dmontoro          #+#    #+#             */
/*   Updated: 2022/08/21 11:20:15 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

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

static long long int	aux_fun(const int n, int *sign)
{
	long long int	aux;

	*sign = 0;
	aux = n;
	if (aux < 0)
	{	
		*sign = 1;
		aux = -aux;
	}
	return (aux);
}

char	*ft_itoa(int n)
{
	int				sign;
	char			*ret;
	int				i;
	int				digs;
	long long int	aux;

	i = 0;
	aux = aux_fun(n, &sign);
	digs = digits(aux);
	ret = malloc((digs + sign + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	while (digs > 0)
	{
		ret[i] = (aux % 10) + '0';
		aux = aux / 10;
		++i;
		digs--;
	}
	if (sign)
		ret[i++] = '-';
	ret[i] = '\0';
	ft_strrev(ret);
	return (ret);
}

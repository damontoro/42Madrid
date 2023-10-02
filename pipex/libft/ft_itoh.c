/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:14:37 by dmontoro          #+#    #+#             */
/*   Updated: 2022/08/30 18:33:15 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:00:59 by dmontoro          #+#    #+#             */
/*   Updated: 2022/08/29 17:10:21 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digs(unsigned long long int num)
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
	char			*ret;
	int				i;
	int				sign;
	long long int	aux;

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
	ret[i++] = "0123456789abcdef"[aux];
	ret[i] = '\0';
	return (ret);
}

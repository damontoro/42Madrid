/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:00:59 by dmontoro          #+#    #+#             */
/*   Updated: 2022/08/29 18:40:19 by dmontoro         ###   ########.fr       */
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

char	*ft_uitoh(unsigned long long int num)
{
	char					*ret;
	int						i;
	unsigned long long int	aux;

	aux = num;
	ret = malloc(sizeof(char) * (digs(aux) + 1));
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

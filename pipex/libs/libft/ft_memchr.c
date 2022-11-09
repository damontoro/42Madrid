/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:40:52 by dmontoro          #+#    #+#             */
/*   Updated: 2022/08/21 13:24:23 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*aux;

	aux = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (aux[i] == (unsigned char)c)
			return ((void *)(aux + i));
		i++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:45:18 by dmontoro          #+#    #+#             */
/*   Updated: 2022/08/09 13:10:35 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*a1;
	unsigned char	*a2;

	a1 = (unsigned char *) s1;
	a2 = (unsigned char *) s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && a1[i] == a2[i])
		++i;
	return (a1[i] - a2[i]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 12:09:08 by dmontoro          #+#    #+#             */
/*   Updated: 2022/09/04 16:41:32 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	char	*ret;

	if (!n || (SIZE_MAX / n > size))
		return (NULL);
	ret = malloc(n * size);
	if (!ret)
		return (NULL);
	ft_bzero(ret, n * size);
	return (ret);
}

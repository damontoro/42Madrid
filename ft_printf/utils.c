/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 07:53:11 by dmontoro          #+#    #+#             */
/*   Updated: 2022/08/29 08:31:37 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	recursive_magic(int n, int fd)
{
	if (n < 10)
		ft_putchar_fd(n + '0', fd);
	else
	{
		recursive_magic(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}

void	ft_putunbr_fd(unsigned int n, int fd)
{
	recursive_magic(n, fd);
}

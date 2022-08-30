/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 20:58:29 by dmontoro          #+#    #+#             */
/*   Updated: 2022/08/30 17:34:26 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

#define FUN_NMB 7

int		ft_printf(char const *s, ...);

int		parse_var(const char c, va_list list);
int		parse_char(const char c, va_list list);
int		parse_string(const char c, va_list list);
int		parse_per(const char c, va_list list);
int		parse_int(const char c, va_list list);
int		parse_uint(const char c, va_list list);
int		parse_hexa(const char c, va_list list);
int		parse_pointer(const char c, va_list list);

void	ft_putunbr_fd(unsigned int n, int fd);


#endif
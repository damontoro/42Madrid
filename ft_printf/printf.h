/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 20:58:29 by dmontoro          #+#    #+#             */
/*   Updated: 2022/08/21 20:58:29 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_h

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#define FUN_NMB 5

int		printf(char const *s, ...);

int		parse_var(const char c, va_list list);
int		parse_char(const char c, va_list list);
int		parse_string(const char c, va_list list);
int		parse_int(const char c, va_list list);


#endif
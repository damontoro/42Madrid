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
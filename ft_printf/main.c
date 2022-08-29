#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

#define SCHAR_MAX __SCHAR_MAX__
#define SHRT_MAX  __SHRT_MAX__
#define INT_MAX   __INT_MAX__
#define LONG_MAX  __LONG_MAX__

#define SCHAR_MIN (-__SCHAR_MAX__-1)
#define SHRT_MIN  (-__SHRT_MAX__ -1)
#define INT_MIN   (-__INT_MAX__  -1)
#define LONG_MIN  (-__LONG_MAX__ -1L)

#define UCHAR_MAX (__SCHAR_MAX__*2  +1)
#define USHRT_MAX (__SHRT_MAX__ *2  +1)
#define UINT_MAX  (__INT_MAX__  *2U +1U)
#define ULONG_MAX (__LONG_MAX__ *2UL+1UL)


int main(){

	int s = printf("%d", INT_MIN);
	printf("\n");
	int m = ft_printf("%d", INT_MIN);

	printf("\n%i, %i\n", s, m);
	return 0;
}
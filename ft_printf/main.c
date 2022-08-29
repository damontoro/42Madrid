#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "printf.h"


int main(){

	printf("%u %i %d\n", (unsigned int) -10, ((unsigned int) -10), -10);
	ft_printf("%u %i %d\n", (unsigned int) -10, ((unsigned int) -10), -10);

	return 0;
}
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "printf.h"


int main(){

	printf("STD: %X\n", -2);
	ft_printf("Mio: %X\n", -2);
	return 0;
}
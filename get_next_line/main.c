#include"get_next_line.h"
#include<stdio.h>
#include<unistd.h>
#include <fcntl.h> 
#include <string.h>

int main(){
	int fd = open("/home/souls/Proyectos42/42Madrid/get_next_line/pruebas.txt", O_RDONLY);
	
	while ( printf("%s", get_next_line(fd)) > 0){}
	
	return 0;
}
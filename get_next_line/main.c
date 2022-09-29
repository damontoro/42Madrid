#include"get_next_line_bonus.h"
#include<stdio.h>
#include<unistd.h>
#include <fcntl.h> 
#include <string.h>
#include <sys/time.h>

int main(){
	int fd1= open("/home/souls/Proyectos42/42Madrid/get_next_line/pruebas.txt", O_RDONLY);
	int fd2= open("/home/souls/Proyectos42/42Madrid/get_next_line/pruebas2.txt", O_RDONLY);

	//printf("FD_SETSIZE=%d", FOPEN_MAX);
	while(printf("%s", get_next_line(fd1)) > 0){
		printf("%s", get_next_line(fd2));
	}
	
	return 0;
}
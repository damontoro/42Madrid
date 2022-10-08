#include"get_next_line_bonus.h"
#include<stdio.h>
#include<unistd.h>
#include <fcntl.h> 
#include <string.h>

void leaks()
{
	system("leaks a.out");
}

int main(){
	int fd= open("/Users/dmontoro/Desktop/42Madrid/get_next_line/pruebas.txt", O_RDONLY);
	int fd2= open("/Users/dmontoro/Desktop/42Madrid/get_next_line/pruebas2.txt", O_RDONLY);

	char * a = get_next_line(fd);
	printf("%s", a);
	char *b = get_next_line(fd2);
	while(a != NULL)
	{
		printf("%s", a);
		printf("%s", b);
		free(a);
		free(b);
		a = get_next_line(fd);
		b = get_next_line(fd2);

	}
	free(a);
	free(b);

	//atexit(leaks);
	return 0;
}
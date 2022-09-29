#include"get_next_line.h"
#include<stdio.h>
#include<unistd.h>
#include <fcntl.h> 
#include <string.h>

void leaks()
{
	system("leaks a.out");
}

int main(){
	int fd= open("/Users/dmontoro/Desktop/42Madrid/get_next_line/gnlTester/files/big_line_no_nl", O_RDONLY);
	int fd2= open("/Users/dmontoro/Desktop/42Madrid/get_next_line/pruebas2.txt", O_RDONLY);

	char * a = get_next_line(fd);
	while(a != NULL)
	{
		printf("%s", a);
		a = get_next_line(fd);
	}

	//atexit(leaks);
	return 0;
}
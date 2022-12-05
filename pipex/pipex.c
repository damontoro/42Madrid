#include "pipex.h"


int main(int argc, char *const argv[], char *const envp[])
{
	// el 0 es reading el 1 es writing, para usar uno cerrar el otro
	char *ma[] = {"grep", "1", NULL};
	char *ma2[] = {"wc", "-l", NULL};
	int	fd[2];
	pid_t	childpid;
	int a = pipe(fd);
	int f = open("pruebas.txt", O_RDONLY);

	dup2(f, STDIN_FILENO);

	for(int i = 0; i < 2; i++)
	{
		dup2(f, STDIN_FILENO);
		childpid = fork();
		if(childpid == 0)
		{
			waitpid(childpid, NULL, 0);
			printf("Una vuelta1\n");
			/*close(fd[0]);
			dup2(fd[1], STDOUT_FILENO);
			close(fd[1]);
			execve("/usr/bin/grep", ma, envp);*/

		}
		else
		{
			char c;
			printf("Una vuelta2\n");
			close(fd[1]);
			//dup2(fd[0], STDIN_FILENO);
			//close(fd[0]);
			execve("/usr/bin/wc", ma2, envp);

		}
	}
	return (0);
}
#include "pipex.h"

void freeMemoria(char **c, char *path, char *aux)
{
	int j;

	j = 0;
	while (c[j] != NULL)
	{
		free(c[j]);
		j++;
	}
	free(c);
	free(path);
	free(aux);
}

char *findPath(char * const*envp, char *command){
	int		i;
	char	**paths;
	int		j;
	char	*path;
	char	*ret = NULL;
	
	i = 0;
	while (envp[i] != NULL && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	paths = ft_split(envp[i], ':');
	j = -1;
	while (paths[j] != NULL)
	{
		if (j == -1)
			path = ft_strjoin("", command);
		else
			path = ft_strjoin(paths[j], command);
		j++;
		if(access(path, F_OK | X_OK) == 0)
		{
			ret = ft_strdup(path);
			break;
		}
		free(path);
	}
	if(ret == NULL)
	{
		perror("Error: command not found");
		exit(127);
	}
	j = 0;
	while (paths[j] != NULL)
	{
		free(paths[j]);
		j++;
	}
	free(paths);
	return (ret);
}

void exCommand(char *path, char **c, char *const envp[])
{
	free(c[0]);
	c[0] = path;
	if (execve(path, c, envp) == -1)
	{
		perror("Error: execve");
		exit(1);
	} //El codigo acaba aqui

}

void iniData(struct data *d, char *const argv[], const int argc){
	d->inFile = open(argv[1], O_RDONLY | O_CLOEXEC, 0600);
	d->outFile = open(argv[argc - 1],O_CREAT | O_WRONLY | O_TRUNC | O_CLOEXEC, 0600);
	dup2(d->inFile, STDIN_FILENO); //Clonamos stdin en el fichero para leer del fichero
	close(d->inFile);
}

void manageChild(struct data *d, int argc, int i, int fd[], char *const envp[]){
	d->childpid = fork();
	if(d->childpid == 0)
	{
		close(fd[0]);
		if (i == argc - 2)
		{
			if (d->outFile == -1)
				exit(1);
			dup2(d->outFile, STDOUT_FILENO); //Clonamos la salida estandar en el fichero para escribir en el fichero
			close(d->outFile);
		}
		else{
			dup2(fd[1], STDOUT_FILENO); //Clonamos la salida estandar en el pipe para escribir en el pipe
			close(fd[1]);
		}
		exCommand(d->path,d->comm, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO); //Clonamos stdin en el pipe para leer del pipe
		close(fd[0]);
		freeMemoria(d->comm, d->path, d->aux);
	}
}

int main(int argc, char *const argv[], char *const envp[])
{
	struct data d;
	int i;
	int fd[2];

	if (!envp || !*envp)
		exit(127);
	if (argc < 5)
	{
		perror("Error: numero de argumentos incorrecto\n");
		exit(1);
	}
	iniData(&d, argv, argc);
	i = 2;
	while (i < argc - 1)
	{
		pipe(fd);
		d.comm = ft_split(argv[i], ' ');
		d.aux = ft_strjoin("/", d.comm[0]);
		d.path = findPath(envp, d.aux);
		manageChild(&d, argc, i, fd, envp);
		if(i == argc - 2)
		{
			waitpid(d.childpid, &d.exit, 0);
			if (WIFEXITED(d.exit))
				d.exit = WEXITSTATUS(d.exit);
			printf("exit status: %d\n", d.exit);
		}
		i++;
	}
	return (d.exit);
}


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
	j = 0;
	while(paths[j] != NULL){
		j++;
		path = ft_strjoin(paths[j], command);
		if(access(path, F_OK | X_OK) == 0){
			if(ret == NULL)
				ret = ft_strdup(path);
		}
		free(path);
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
	execve(path, c, envp);
}

struct data{
	char **comm;
	char *path;
	char *aux;
	int fd[2];
	int inFile;
	int outFile;
	pid_t childpid;
};

void iniData(struct data *d, char *const argv[], const int argc){
	d->inFile = open(argv[1], O_RDONLY, 0666);
	d->outFile = open(argv[argc - 1],O_RDWR |  O_CREAT | O_TRUNC, 0666);
	if(pipe(d->fd) == -1)
	{
		perror("Error: pipe");
		exit(1);
	}
	dup2(d->inFile, STDIN_FILENO); //Clonamos stdin en el fichero para leer del fichero
	close(d->inFile);
}

int main(int argc, char *const argv[], char *const envp[])
{
	struct data d;
	int i;

	if (argc < 5)
	{
		perror("Error: numero de argumentos incorrecto\n");
		exit(1);
	}
	// el 0 es reading el 1 es writing, para usar uno cerrar el otro

	iniData(&d, argv, argc);
	i = 2;
	while (i < argc - 1)
	{
		d.comm = ft_split(argv[i], ' ');
		d.aux = ft_strjoin("/", d.comm[0]);
		d.path = findPath(envp, d.aux);

		d.childpid = fork();
		if(d.childpid == 0)
		{
			close(d.fd[0]);
			if (i == argc - 2)
			{
				dup2(d.outFile, STDOUT_FILENO); //Clonamos la salida estandar en el fichero para escribir en el fichero
				close(d.outFile);
			}
			else{
				dup2(d.fd[1], STDOUT_FILENO); //Clonamos la salida estandar en el pipe para escribir en el pipe
				close(d.fd[1]);
			}
			exCommand(d.path,d.comm, envp);
		}
		else
		{
			waitpid(d.childpid, NULL, 0);
			close(d.fd[1]);
			dup2(d.fd[0], STDIN_FILENO); //Clonamos stdin en el pipe para leer del pipe
			close(d.fd[0]);
			freeMemoria(d.comm, d.path, d.aux);
		}
		i++;
	}
	return (0);
}


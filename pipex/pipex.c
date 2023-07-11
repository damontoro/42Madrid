/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:41:18 by dmontoro          #+#    #+#             */
/*   Updated: 2023/07/11 20:17:56 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_memoria(char **c, char *path, char *aux)
{
	int	j;

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

void	ex_command(char *path, char **c, char **envp)
{
	free(c[0]);
	c[0] = path;
	if (!path)
	{
		perror("Error: command not found: invalid argument\n");
		exit(127);
	}
	if (execve(path, c, envp) == -1)
	{
		perror("Error: execve");
		exit(1);
	}
}

void	ini_data(t_data *d, char *const argv[], const int argc)
{
	d->in_file = open(argv[1], O_RDONLY | O_CLOEXEC, 0600);
	d->out_file = open(argv[argc - 1], O_CREAT | \
	O_WRONLY | O_TRUNC | O_CLOEXEC, 0644);
	if (d->in_file != -1)
	{
		dup2(d->in_file, STDIN_FILENO);
		close(d->in_file);
	}
}

void	manage_child(t_data *d, int argc, \
int i, char *envp[])
{
	d->childpid = fork();
	if (d->childpid == 0)
	{
		manage_child_fds(i, argc, d);
		ex_command(d->path, d->comm, envp);
	}
	else
	{
		close(d->fd[1]);
		dup2(d->fd[0], STDIN_FILENO);
		close(d->fd[0]);
		free_memoria(d->comm, d->path, d->aux);
	}
}

int	main(int argc, char *const argv[], char *envp[])
{
	t_data	d;
	int		i;

	if (!envp || !*envp)
		exit(127);
	if (argc < 5)
	{
		perror("Error: numero de argumentos incorrecto\n");
		exit(1);
	}
	ini_data(&d, argv, argc);
	i = 2;
	while (i < argc - 1)
	{
		pipe(d.fd);
		d.comm = parse_command(argv[i]);
		// for(int j = 0; d.comm[j] != NULL; j++)
		// 	printf("%s\n", d.comm[j]);
		d.aux = ft_strjoin("/", d.comm[0]);
		d.path = find_path(envp, d.aux);
		manage_child(&d, argc, i, envp);
		last_child(i, argc, &d);
		i++;
	}
	return (d.exit);
}



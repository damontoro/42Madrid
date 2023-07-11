/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipexAux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:50:15 by dmontoro          #+#    #+#             */
/*   Updated: 2023/07/11 17:47:21 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	check_access(char *path, char **ret)
{
	if (access(path, F_OK | X_OK) == 0)
	{
		*ret = ft_strdup(path);
		free (path);
		return (0);
	}
	else
		return (1);
}

char	*find_path(char **envp, char *command)
{
	int		i;
	char	**paths;
	int		j;
	char	*path;
	char	*ret;

	i = 0;
	ret = NULL;
	
	while (envp[i] != NULL && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	j = -1;
	path = ft_strjoin("", command);
	while (j == -1 || paths[j] != NULL)
	{
		if (j != -1)
			path = ft_strjoin(paths[j], command);
		if (check_access(path, &ret) == 0){
			break ;
		}
		j++;
		free (path);
	}
	free_split(paths);
	return (ret);
}

void	last_child(int i, int argc, t_data *d)
{
	if (i == argc - 2)
	{
		waitpid(d->childpid, &d->exit, 0);
		if (WIFEXITED(d->exit))
			d->exit = WEXITSTATUS(d->exit);
	}
}

void	manage_child_fds(int i, int argc, t_data *d)
{
	close(d->fd[0]);
	if (i == argc - 2)
	{
		close (d->fd[1]);
		if (d->out_file == -1){
			exit(1);
		}
		dup2(d->out_file, STDOUT_FILENO);
		close(d->out_file);
	}
	else
	{
		if (d->in_file < 0)
		{
			perror("Error: no such file or directory");
			close(d->fd[1]);
			if (d->out_file != -1)
				close (d->out_file);
			exit(0);
		}
		dup2(d->fd[1], STDOUT_FILENO);
		close(d->fd[1]);
	}
}

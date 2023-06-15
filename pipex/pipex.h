/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:04:51 by dmontoro          #+#    #+#             */
/*   Updated: 2023/06/15 20:07:40 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libs/libft/libft.h"

typedef struct s_data{
	char	**comm;
	char	*path;
	char	*aux;
	int		in_file;
	int		out_file;
	int		exit;
	pid_t	childpid;
	int		fd[2];
}	t_data;

char	*find_path(char **envp, char *command);
void	last_child(int i, int argc, t_data *d);
void	manage_child_fds(int i, int argc, t_data *d);

#endif
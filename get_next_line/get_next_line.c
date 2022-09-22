/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:11:31 by dmontoro          #+#    #+#             */
/*   Updated: 2022/09/22 18:34:24 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int linelen(char *a)
{
	int	i;

	i = 0;
	while (a[i] != '\0' && a[i] != '\n')
		i++;
	return (i);
}

void override_buffer(char saved[BUFFER_SIZE], int pos)
{
	int	i;

	i = 0;
	while (saved[pos] != '\0')
	{
		saved[i] = saved[pos];
		i++;
		pos++;
	}
	while (i < pos)
	{
		saved[i] = '\0';
		i++;
	}
}

char	*load_saved(char saved[BUFFER_SIZE])
{
	char	*aux;
	int		i;
	int		fin;

	i = 0;
	fin = 0;
	aux = NULL;
	while (saved[i] && !fin)
	{
		if(saved[i] == '\n')
			fin = 1;
		i++;
	}
	aux = malloc((i + 1) * sizeof(char));
	ft_strlcpy(aux, saved, i + 1);
	override_buffer(saved, i);
	return (aux);
}

char	*load_buffer(int fd, char *saved)
{
	char	*ret;
	int		rd;

	if(!saved)
		saved = ft_strdup("");
	while (!ft_strchr(saved, '\n'))
	{
		ret = (char *)malloc(BUFFER_SIZE + 1);
		if (!ret)
			return (NULL);
		r

	}
	
}

char	*read_file(int fd, char *saved)
{
	char	*buffer;
	char	*ret;
	int		i;
	int		count;
	int		j;
	char 	*found;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if(!buffer)
		return NULL;
	while (!found && (count = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		found = ft_strchr(buffer, '\n');
		ret = ft_strjoin(ret, ft_substr(buffer, 0, linelen(buffer)));
		i = 0; 
		while (found && found[i] != '\0'){
			saved[j] = found[i];
			j++; 
			i++;
		}
	}
	free(buffer);
	if(count < 0)
		return (NULL);
	return ret;
}

char *get_next_line(int fd)
{
	static char	saved[BUFFER_SIZE];
	char	*buffer;
	char	*ret;

	ret = load_saved(saved);
	if(!ft_strchr(ret, '\n'))
		ret = read_file(fd, saved);
	return (ret);
}

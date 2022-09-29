/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:11:31 by dmontoro          #+#    #+#             */
/*   Updated: 2022/09/29 20:24:47 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int line_len(char *a)
{
	int	i;

	i = 0;
	while (a[i] != '\0' && a[i] != '\n')
		i++;
	if (a[i] == '\n')
		i++;
	return (i);
}

static char	*override_buffer(char *saved)
{
	char	*ret;
	size_t	pos;
	size_t	size;
	size_t	i;

	i = 0;
	pos = line_len(saved);
	if (!saved[pos])
	{
		free(saved);
		return (NULL);
	}
	size = ft_strlen(saved);
	ret = (char *)malloc((size - pos + 2) * sizeof(char));
	if (!ret)
		return(NULL);
	while (saved[pos]){
		ret[i] = saved[pos];
		i++;
		pos++;
	}
	ret[i] = '\0';
	free(saved);
	return (ret);
}

static char	*load_saved(int fd, char *saved)
{
	char	*ret;
	int		count;

	count = 1;
	ret = (char *)malloc(BUFFER_SIZE + 1);
	if (!ret)
		return (NULL);
	while (ft_strchr(saved, '\n') == NULL && count != 0)
	{
		count = read(fd, ret, BUFFER_SIZE);
		if (count == -1)
		{
			free(ret);
			return (NULL);
		}
		ret[count] = '\0';
		if (!saved)
			saved = ft_strdup(ret);
		else
			saved = ft_strjoin(saved, ret);
	}
	free(ret);
	return (saved);
}

static char	*read_line(char *saved)
{
	size_t	size;
	size_t	i;
	char	*ret;

	i = 0;
	if (!saved[i])
		return (NULL);
	size = line_len(saved);
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	while (i < size)
	{
		ret[i] = saved[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*saved[OPEN_MAX];
	char	*ret;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	saved[fd] = load_saved(fd, saved[fd]);
	if (!saved[fd])
		return (NULL);
	ret = read_line(saved[fd]);
	saved[fd] = override_buffer(saved[fd]);
	return (ret);
}

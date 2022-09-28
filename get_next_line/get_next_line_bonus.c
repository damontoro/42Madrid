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

#include "get_next_line_bonus.h"

static int line_len(char *a)
{
	int	i;

	i = 0;
	while (a[i] != '\0' && a[i] != '\n')
		i++;
	return (i + 1);
}

static char	*override_buffer(char *saved)
{
	char	*ret;
	size_t	pos;
	size_t	size;
	size_t	i;

	i = 0;
	size = ft_strlen(saved);
	pos = line_len(saved);
	ret = (char *)malloc((size - pos + 1) * sizeof(char));
	if (!ret)
		return(NULL);
	while (saved[pos]){
		ret[i] = saved[pos];
		i++;
		pos++;
	}
	return (ret);
}

static char	*load_saved(int fd, char *saved)
{
	char	*ret;
	int		count;

	count = 1;
	if(!saved)
		saved = ft_strdup("");
	while (ft_strchr(saved, '\n') == NULL && count > 0)
	{
		ret = (char *)malloc(BUFFER_SIZE + 1);
		if (!ret)
			return (NULL);
		count = read(fd, ret, BUFFER_SIZE);
		if (count < 0){
			free(ret);
			return (NULL);
		}
		saved = ft_strjoin(ret, saved);
		free(ret);
	}
	return (saved);
}

static char	*read_line(char *saved)
{
	int		size;
	char	*ret;

	size = line_len(saved);
	ret = malloc((size + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	ret = ft_substr(saved, 0, size);
	return (ret);
}

char *get_next_line(int fd)
{
	static char	*saved[FOPEN_MAX];
	char	*ret;

	saved[fd] = load_saved(fd, saved[fd]);
	if (!saved[fd])
		return (NULL);
	ret = read_line(saved[fd]);
	saved[fd] = override_buffer(saved[fd]);
	return (ret);
}

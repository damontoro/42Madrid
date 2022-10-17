/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:11:33 by dmontoro          #+#    #+#             */
/*   Updated: 2022/09/30 07:13:51 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	ft_strlen_gnl(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

char	*ft_strdup_gnl(const char *s1)
{
	char	*new;
	int		i;

	new = (char *)malloc((ft_strlen_gnl(s1) + 1) * sizeof(char));
	if (!new)
		return (0);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strjoin_gnl(char *s1, const char *s2)
{
	char	*ret;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	ret = malloc((ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		ret[i] = s2[j];
		i++;
		j++;
	}
	ret[i] = '\0';
	free((void *)s1);
	return (ret);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	size_t	i;
	size_t	size;

	i = 0;
	if (!s)
		return (NULL);
	size = ft_strlen_gnl(s);
	while (i < size)
	{
		if (s[i] == (char) c)
			return ((char *) s + i);
		i++;
	}
	return (NULL);
}

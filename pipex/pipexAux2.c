/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipexAux2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 10:36:29 by dmontoro          #+#    #+#             */
/*   Updated: 2023/07/12 12:05:50 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	word_size(const char *s, char c)
{
	int	ret;
	int	i;

	i = 0;
	ret = 0;
	while (s[i] && s[i] != c)
	{
		if (check_comillas('\'', s, i))
		{
			if (i == 0)
				return (check_comillas('\'', s, i));
			return (ret);
		}
		if (check_comillas('\"', s, i))
		{
			if (i == 0)
				return (check_comillas('\"', s, i));
			return (ret);
		}
		ret++;
		i++;
	}
	return (ret);
}

static int	skip_char(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] == c && s[i])
		i++;
	return (i);
}

static char	*manage_malloc(char **res, const char *s, char c, int i)
{
	char	*ret;

	ret = malloc((word_size(s, c) + 1) * sizeof(char));
	if (!ret)
	{
		while (i-- > 0)
			free(res[i]);
		free(res);
		return (NULL);
	}
	return (ret);
}

void static	copy_word(char **ret, const char *s, char c, int *indexes)
{
	int	comillas;

	ret[indexes[0]] = manage_malloc(ret, &s[indexes[1]], c, indexes[0]);
	if (!ret[indexes[0]])
		return ;
	comillas = (check_comillas('\'', s, indexes[1]) || \
		check_comillas('\"', s, indexes[1]));
	ret[indexes[0]] = ft_substr(s, (indexes[1]) + comillas, \
		word_size(&s[indexes[1]], c) - comillas);
	indexes[1] += word_size(&s[indexes[1]], c) + comillas;
	indexes[1] += skip_char(&s[indexes[1]], c);
	(indexes[0])++;
}

char	**split_args(char const *s, char c)
{
	int		num_words;
	char	**ret;
	int		indexes[2];

	if (!s)
		return (NULL);
	indexes[0] = 0;
	indexes[1] = skip_char(&s[0], c);
	num_words = count_words(s, c) + 1;
	ret = malloc((num_words) * sizeof(char *));
	if (!ret)
		return (NULL);
	ret[num_words - 1] = 0;
	while (--num_words > 0)
	{
		copy_word(ret, s, c, &indexes[0]);
		if (!ret[indexes[0] - 1])
			return (NULL);
	}
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipexAux2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 10:36:29 by dmontoro          #+#    #+#             */
/*   Updated: 2023/07/12 10:39:35 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	found;
	int	i;

	i = 0;
	found = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '\'')
		{
			while (s[++i] && s[i] != '\'')
				;
			count++;
			i++;
		}
		if (s[i] == '\"')
		{
			while (s[++i] && s[i] != '\"')
				;
			count++;
			i++;
		}
		while (s[i] != c && s[i])
		{
			if (!found)
			{
				count++;
				found = 1;
			}
			++i;
		}
		while (s[i] == c && s[i])
		{
			found = 0;
			++i;
		}
	}
	return (count);
}

int check_comillas(char c, const char *s, int i)
{
	int	j;

	if (s[i] != c)
		return (0);
	j = i + 1;
	while (s[j] && s[j] != c)
		j++;
	if (s[j] == c)
		return (j - i);
	return (0);
}

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

void static copy_word(char **ret, const char *s, char c, int *i, int *j)
{
	int	comillas;
	
	ret[*i] = manage_malloc(ret, &s[*j], c, *i);
	if(!ret[*i])
		return;
	comillas = (check_comillas('\'', s, *j) || check_comillas('\"', s, *j));
	ret[*i] = ft_substr(s, (*j) + comillas, word_size(&s[*j], c) - comillas);
	*j += word_size(&s[*j], c) + comillas;
	*j += skip_char(&s[*j], c);
	(*i)++;
}

char	**split_args(char const *s, char c)
{
	int		num_words;
	char	**ret;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	j = skip_char(&s[0], c);
	num_words = count_words(s, c) + 1;
	ret = malloc((num_words) * sizeof(char *));
	if (!ret)
		return (NULL);
	ret[num_words - 1] = 0;
	while (--num_words > 0)
	{
		copy_word(ret, s, c, &i, &j);
		if (!ret[i - 1])
			return (NULL);
	}
	return (ret);
}


char **parse_command(char *command)
{
	char **c;

	c = split_args(command, ' ');
	return (c);
}

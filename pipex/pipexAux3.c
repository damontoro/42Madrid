/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipexAux3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:50:07 by dmontoro          #+#    #+#             */
/*   Updated: 2023/07/13 11:20:32 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	jump_quotes(char const *s, int *i, int *count)
{
	if (s[*i] == '\'')
	{
		while (s[++(*i)] && s[*i] != '\'')
			;
		(*i)++;
		(*count)++;
	}
	if (s[*i] == '\"')
	{
		while (s[++(*i)] && s[*i] != '\"')
			;
		(*i)++;
		(*count)++;
	}
}

int	count_words(char const *s, char c)
{
	int	count;
	int	found;
	int	i;

	i = 0;
	found = 0;
	count = 0;
	while (s[i])
	{
		jump_quotes(s, &i, &count);
		while (s[i] != c && s[i])
		{
			if (!found)
			{
				count++;
				found = 1;
			}
			++i;
		}
		while (s[i] == c && s[i++])
			found = 0;
	}
	return (count);
}

int	check_comillas(char c, const char *s, int i)
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

void	ft_error(char *str, int code)
{
	perror(str);
	exit(1);
}

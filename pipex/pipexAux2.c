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
		if(s[i] == '\'' || s[i] == '\"')
		{
			while (s[++i] && s[i] != '\'' && s[i] != '\"');
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

static int	word_size(const char *s, char c)
{
	int	ret;
	int	i;

	i = 0;
	ret = 0;
	while (s[i] && s[i] != c)
	{
		if(s[i] == '\'' || s[i] == '\"')
		{
			i++; ret++;
			while (s[i] && s[i] != '\'' && s[i] != '\"'){
				ret++;
				i++;
			}
			ret++; i++;
			continue;
		}
		ret++;
		++i;
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
	printf("num_words: %d\n", num_words);
	ret = malloc((num_words) * sizeof(char *));
	if (!ret)
		return (NULL);
	ret[num_words - 1] = 0;
	while (--num_words > 0)
	{
		ret[i] = manage_malloc(ret, &s[j], c, i);
		if (!ret[i])
			return (NULL);
		ft_strlcpy(ret[i], &s[j], (size_t) word_size(&s[j], c) + 1);
		i++;
		j += word_size(&s[j], c);
		j += skip_char(&s[j], c);
	}
	return (ret);
}


char **parse_command(char *command)
{
	char **c;

	c = split_args(command, ' ');
	return (c);
}
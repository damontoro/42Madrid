/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 12:32:47 by dmontoro          #+#    #+#             */
/*   Updated: 2022/08/21 13:11:50 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	is_in_set(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	int		i;
	size_t	j;
	size_t	k;

	if (!set || !s1)
		return (NULL);
	if (*s1 == '\0')
		return (ft_strdup(""));
	i = 0;
	j = 0;
	k = ft_strlen(s1) - 1;
	while (k > 0 && is_in_set(s1[k], set))
		k--;
	while (j < ft_strlen(s1) && is_in_set(s1[j], set))
		j++;
	if (k == 0)
		return (ft_strdup(""));
	ret = malloc((k - j + 2) * sizeof(char));
	if (!ret)
		return (NULL);
	while (j <= k)
		ret[i++] = s1[j++];
	ret[i] = '\0';
	return (ret);
}

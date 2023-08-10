/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 07:36:09 by dmontoro          #+#    #+#             */
/*   Updated: 2023/08/10 10:55:25 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isspace(int c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

time_t	ft_time(void)
{
	struct timeval	time;
	time_t				ret;

	gettimeofday(&time, NULL);
	ret = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ret);
}

void	print_and_wait(char c, int id, time_t t_start, time_t wait_time)
{
	time_t	start;

	if (c == 'e')
		printf("%ld : Philo %d is eating\n", ft_time() - t_start, id);
	else if (c == 's')
		printf("%ld : Philo %d is sleeping\n", ft_time() - t_start, id);
	else if (c == 't')
		printf("%ld : Philo %d is thinking\n", ft_time() - t_start, id);
	else if (c == 'd')
		printf("%ld : Philo %d is dead\n", ft_time() - t_start, id);

	start = ft_time();
	while (ft_time() - start < wait_time)
		usleep(100);
}
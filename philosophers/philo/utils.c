/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 07:36:09 by dmontoro          #+#    #+#             */
/*   Updated: 2023/12/14 17:55:44 by dmontoro         ###   ########.fr       */
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
	time_t			ret;

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
		printf("%ld : Philo %d died\n", ft_time() - t_start, id);
	start = ft_time();
	while (ft_time() - start < wait_time)
		usleep(100);
}

int	check_data(t_table *table, int argc)
{
	if (table->n_philo < 1 || table->t_die < 0 || table->t_eat < 0
		|| table->t_sleep < 0)
	{
		printf("Error: negative values\n");
		return (1);
	}
	if (argc == 6 && table->n_eat <= 0)
	{
		printf("Error: n_eat can't be <= 0\n");
		return (1);
	}
	return (0);
}

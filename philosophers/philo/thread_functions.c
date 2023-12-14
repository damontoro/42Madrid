/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 12:57:52 by dmontoro          #+#    #+#             */
/*   Updated: 2023/12/14 11:33:29 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_mutex);
		if (*philo->dead == 1)
		{
			pthread_mutex_unlock(philo->dead_mutex);
			return (1);
		}
	pthread_mutex_unlock(philo->dead_mutex);
	return (0);
}

void	*philo_routine(void *data)
{
	t_philo	*philo;
	int		end;

	philo = (t_philo *)data;

	while (1)
	{
		if (check_dead(philo))
			break ;
		if (!take_forks(philo))
			continue ;
		end = eat(philo);
		release_forks(philo);
		sleep_(philo);
		think(philo);
		if (end)
			break ;
	}
	return (NULL);
}

void	monitor(t_table *table)
{
	int	i;

	while (1)
	{
		i = 0;
		pthread_mutex_lock(&table->full_mutex);
		if (table->full == table->n_philo)
		{
			pthread_mutex_unlock(&table->full_mutex);
			break ;
		}
		pthread_mutex_unlock(&table->full_mutex);
		while(i < table->n_philo)
		{
			pthread_mutex_lock(&table->philo_data[i]->data_mutex);
			if(ft_time() - table->philo_data[i]->last_eat > table->t_die)
			{
				pthread_mutex_lock(&table->dead_mutex);
				table->dead = 1;
				pthread_mutex_unlock(&table->dead_mutex);
				print_and_wait('d', table->philo_data[i]->id, table->t_start, 0);
				pthread_mutex_unlock(&table->philo_data[i]->data_mutex);
				break ;
			}
			pthread_mutex_unlock(&table->philo_data[i]->data_mutex);
			i++;
		}
		if (table->dead == 1)
			break ;
	}
}

void	free_table(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_philo)
	{
		pthread_mutex_destroy(&table->philo_data[i]->left);
		pthread_mutex_destroy(&table->philo_data[i]->data_mutex);
		free(table->philo_data[i]->fork[1]);
		free(table->philo_data[i]);
		i++;
	}
	free(table->philo_data);
	pthread_mutex_destroy(&table->dead_mutex);
	pthread_mutex_destroy(&table->full_mutex);
}
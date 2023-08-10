/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 12:57:52 by dmontoro          #+#    #+#             */
/*   Updated: 2023/08/10 07:45:04 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *data)
{
	t_philo *philo;

	philo = (t_philo *)data;
	while(1)
	{
		pthread_mutex_lock(philo->dead_mutex);
		if (*philo->dead == 1)
		{
			pthread_mutex_unlock(philo->dead_mutex);
			break ;
		}
		pthread_mutex_unlock(philo->dead_mutex);

		philo->eaten++;
		pthread_mutex_lock(&philo->data_mutex);
		philo->last_eat = ft_time();
		pthread_mutex_unlock(&philo->data_mutex);
		printf("Soy el philo: %d y he comido: %d\n", philo->id, philo->eaten);

		
		if(philo->eaten == 20){
			pthread_mutex_lock(philo->full_mutex);
			*philo->full = *philo->full + 1;
			pthread_mutex_unlock(philo->full_mutex);
			break;
		}
		usleep(philo->t_eat * 1000);
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
				pthread_mutex_unlock(&table->philo_data[i]->data_mutex);
				pthread_mutex_lock(&table->dead_mutex);
				table->dead = 1;
				pthread_mutex_unlock(&table->dead_mutex);
				printf("El philo %d ha muerto\n", table->philo_data[i]->id);
				break ;
			}
			pthread_mutex_unlock(&table->philo_data[i]->data_mutex);
			i++;
		}
		if (table->dead == 1)
			break ;
	}
}
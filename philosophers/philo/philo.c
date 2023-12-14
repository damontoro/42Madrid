/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 10:58:40 by dmontoro          #+#    #+#             */
/*   Updated: 2023/12/14 17:52:10 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_table	parse_table(int argc, char **argv);
t_philo	*create_philo(t_table *table, int id);
t_philo	**ini_philos(t_table table);
void	launch_threads(t_table table);

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc < 5 || argc > 6)
	{
		printf("Error: Wrong number of arguments\n");
		printf("Usage: ./philo n_philo t_die t_eat t_sleep [n_eat]\n");
		return (1);
	}
	table = parse_table(argc, argv);
	if (check_data(&table, argc))
		return (1);
	table.philo_data = ini_philos(table);
	launch_threads(table);
	return (0);
}

void	launch_threads(t_table table)
{
	int			i;
	pthread_t	*threads;

	threads = malloc(table.n_philo * sizeof(pthread_t));
	i = 0;
	while (i < table.n_philo)
	{
		pthread_create(&threads[i], 0, philo_routine, table.philo_data[i]);
		i++;
	}
	monitor(&table);
	i = 0;
	while (i < table.n_philo)
	{
		pthread_join(threads[i], 0);
		i++;
	}
	free(threads);
	free_table(&table);
}

t_table	parse_table(int argc, char **argv)
{
	t_table	ret;

	memset(&ret, 0, sizeof(t_table));
	ret.n_philo = ft_err_atoi(argv[1]);
	ret.t_die = ft_err_atoi(argv[2]);
	ret.t_eat = ft_err_atoi(argv[3]);
	ret.t_sleep = ft_err_atoi(argv[4]);
	if (argc == 6)
		ret.n_eat = ft_err_atoi(argv[5]);
	else
		ret.n_eat = -1;
	ret.start = 1;
	ret.dead = 0;
	ret.full = 0;
	pthread_mutex_init(&ret.dead_mutex, NULL);
	pthread_mutex_init(&ret.full_mutex, NULL);
	ret.t_start = ft_time();
	return (ret);
}

t_philo	*create_philo(t_table *table, int id)
{
	t_philo	*ret;

	ret = malloc(sizeof(t_philo));
	memset(ret, 0, sizeof(t_philo));
	ret->id = id;
	ret->t_start = table->t_start;
	ret->last_eat = table->t_start;
	ret->t_die = table->t_die;
	ret->t_eat = table->t_eat;
	ret->t_sleep = table->t_sleep;
	ret->n_eat = table->n_eat;
	ret->full = &table->full;
	ret->dead = &table->dead;
	ret->fork[1] = malloc(sizeof(int));
	*ret->fork[1] = 0;
	pthread_mutex_init(&ret->left, NULL);
	pthread_mutex_init(&ret->data_mutex, NULL);
	ret->full_mutex = &table->full_mutex;
	ret->dead_mutex = &table->dead_mutex;
	return (ret);
}

//el fork[0] (el left) es el "mio" y el fork[1] es el del siguiente o la der
t_philo	**ini_philos(t_table table)
{
	t_philo	**ret;
	int		i;

	ret = malloc(table.n_philo * sizeof(t_philo *));
	i = 0;
	while (i < table.n_philo)
	{
		ret[i] = create_philo(&table, i + 1);
		i++;
	}
	i = 0;
	while (i < table.n_philo)
	{
		ret[i]->right = &ret[(i + 1) % table.n_philo]->left;
		ret[i]->fork[0] = ret[(i + 1) % table.n_philo]->fork[1];
		i++;
	}
	return (ret);
}

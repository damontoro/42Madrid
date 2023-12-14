/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:29:04 by dmontoro          #+#    #+#             */
/*   Updated: 2023/12/14 17:53:10 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <limits.h>
# include <unistd.h>
# include <sys/time.h>
# include <string.h>

//18 * 8 bytes 144 bytes	
typedef struct s_philo {
	int				id;
	time_t			t_start;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_eat;
	int				eaten;
	time_t			last_eat;
	int				*full;
	int				*dead;

	int				*fork[2];
	pthread_mutex_t	*right;
	pthread_mutex_t	left;
	pthread_mutex_t	data_mutex;
	pthread_mutex_t	*full_mutex;
	pthread_mutex_t	*dead_mutex;
}					t_philo;

typedef struct s_table{
	int				n_philo;
	time_t			t_start;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_eat;

	int				dead;
	int				full;
	int				start;

	pthread_mutex_t	dead_mutex;
	pthread_mutex_t	full_mutex;
	t_philo			**philo_data;
}					t_table;

void	*philo_routine(void *t_philo);
void	monitor(t_table *table);
void	free_table(t_table *table);

int		take_forks(t_philo *philo);
void	release_forks(t_philo *philo);
int		eat(t_philo *philo);
void	think(t_philo *philo);
void	sleep_(t_philo *philo);

void	print_and_wait(char c, int id, time_t t_start, time_t wait_time);
int		check_dead(t_philo *philo);
time_t	ft_time(void);

int		check_data(t_table *table, int argc);
int		ft_err_atoi(const char *str);
int		ft_isspace(int c);
size_t	ft_strlen(const char *s);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:29:04 by dmontoro          #+#    #+#             */
/*   Updated: 2023/08/03 13:06:42 by dmontoro         ###   ########.fr       */
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
typedef struct s_filo {
	int				id;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_eat; //numero de veces que tiene que comer
	int				eaten; //numero de veces que ha comido
	int				last_eat; //el ultimo momento en el que comio
	int				*full; //same for all filos
	int				*dead; //same for all filos

	int				fork[2];
	pthread_mutex_t	*right; //for fork[0] 
	pthread_mutex_t	*left; //for fork[1] (mine)
	pthread_mutex_t	*data_mutex; //for last_eat
	pthread_mutex_t *full_mutex; //for full
	pthread_mutex_t	*dead_mutex; //for dead
}					t_philo;

typedef struct s_table{
	int				n_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_eat;

	int				dead;//Whether theres a dead filo or not
	int				full; //number of full filos, the ones that have eaten n_eat times
	int				start;

	pthread_mutex_t	*print;
	pthread_mutex_t	*dead_mutex;
	pthread_mutex_t	*full_mutex;
	t_philo			**philo_data; //to access last_eaten
}					t_table;


int		ft_err_atoi(const char *str);
void	*philo_routine(void *t_philo);
int		ft_isspace(int c);
size_t	ft_strlen(const char *s);




#endif
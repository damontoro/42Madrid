/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:29:04 by dmontoro          #+#    #+#             */
/*   Updated: 2023/07/23 12:16:00 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <limits.h>

typedef struct s_filo {
	int				id;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_eat;
	int				last_eat;
	int				eaten;
	int				*full; //same for all filos
	int				*dead; //same for all filos

	int				fork[2];
	pthread_mutex_t	*right; //for fork[0]
	pthread_mutex_t	*left; //for fork[1]
	pthread_mutex_t	*data_mutex; //for last_eat
	pthread_mutex_t *full_mutex; //for full
	pthread_mutex_t	*dead_mutex; //for dead
}					t_filo;

typedef struct s_table{
	int				n_filo;
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
	t_filo			*filo_data; //to access last_eaten
}					t_table;


int	ft_err_atoi(const char *str);



#endif
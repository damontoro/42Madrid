/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 10:58:40 by dmontoro          #+#    #+#             */
/*   Updated: 2023/08/10 08:38:30 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_table	parse_table(int argc, char **argv);
t_philo	*create_philo(t_table *table, int id);
t_philo	**ini_philos(t_table table);
void	launch_threads(t_table table);

/*
	La funcion de cada filosofo va a ser:
		cada filosofo va a comprobar si ha muerto alguien antes de printear con la variable dead
		cada filosofo va a llevar la cuenta de cuantas veces ha comido con la variable eaten y va a sumar uno a full si ha comido n_eat veces
		cada filosofo tendrá en su array forks 1 si tiene cogido el tenedor y 0 si no, este array estará compartido entre filosofos, es decir
			el fork[1] del filosofo N será el fork[0] del N + 1
		cuando un filosofo coma, intentará coger los tenedores y si lo consigue cogera el mutex de datos, actualizara last eaten y comera, y comprobara si tiene que sumar a full
		si no lo consigue, seguirá intentandolo hasta que pueda.

		la funcion de cada filosofo será:
			1. comprobar si ha muerto alguien
			2. coger los tenedores
			3. comer
			4. soltar los tenedores
			5. comprobar si ha comido n_eat veces
			6. dormir
			7. pensar

		Antes de cada subcosa, comprobará si alguien ha muerto para terminar su ejecución en ese momento y no imprimir nada

	La función de la tabla será:
		Comprobar si ha muerto algun filosofo constantemente y actualiazr el valor de dead, para esto cogera los mutex de data de ese filosofo y de dead
		Imprimir mensajes(?)
		Y creo que nada mas
	
	Cada filosofo será un hilo y la tabla estará en el hilo principal a modo de "monitor"


	HAY QUE LIBERAR LOS FILOSOFOS Y DENTRO DE CADA FILOSOFO SU TENEDOR (POS 1)

*/ 


//Los filos están en memoria estatica pero los punteros en dinamica para poder hacer un array dinamico

//Falt filo_data y print
int	main(int argc, char **argv)
{
	t_table	table;

	table = parse_table(argc, argv);
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
}

t_table	parse_table(int argc, char **argv)
{
	t_table	ret;

	memset(&ret, 0, sizeof(t_table));
	ret.t_start = ft_time();
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
	return (ret);
}

t_philo	*create_philo(t_table *table, int id)
{
	t_philo	*ret;

	ret = malloc(sizeof(t_philo));
	memset(ret, 0, sizeof(t_philo)); //para fork, eaten y last_eaten
	ret->id = id;
	ret->t_start = ft_time();
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
	int			i;

	ret = malloc(table.n_philo * sizeof(t_philo));
	i = 0;
	while (i < table.n_philo)
	{
		ret[i] = create_philo(&table, i + 1);
		i++;
	}
	//Ahora queda asignar left a cada filosofo
	i = 0;
	while (i < table.n_philo)
	{
		ret[i]->right = &ret[(i + 1) % table.n_philo]->left;
		ret[i]->fork[0] = ret[(i + 1) % table.n_philo]->fork[1];
		i++;
	}
	return (ret);
}

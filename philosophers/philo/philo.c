/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 10:58:40 by dmontoro          #+#    #+#             */
/*   Updated: 2023/07/23 12:32:12 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	La funcion de cada filosof va a ser:
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
*/ 


t_table parse_table(int argc, char **argv)
{
	t_table	ret;

	memset(&ret, 0, sizeof(t_table));
	ret.n_filo = ft_err_atoi(argv[1]);
	ret.t_die = ft_err_atoi(argv[2]);
	ret.t_eat = ft_err_atoi(argv[3]);
	ret.t_sleep = ft_err_atoi(argv[4]);
	if(argc == 6)
		ret.n_eat = ft_err_atoi(argv[5]);
	else
		ret.n_eat = -1;
	ret.start = 1;



}

int	main(int argc, char **argv)
{
	return (0);
}

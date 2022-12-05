/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxFunctions4_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:49:13 by dmontoro          #+#    #+#             */
/*   Updated: 2022/12/05 12:11:30 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	free_map(t_controller *con)
{
	int	i;

	i = 0;
	while (i < con->game.map.height)
	{
		free(con->game.map.map[i]);
		i++;
	}
	free(con->game.map.map);
}

void	free_ini_sprites(t_controller *con)
{
	mlx_destroy_image(con->vars.mlx, con->sprites->exit);
	mlx_destroy_image(con->vars.mlx, con->sprites->item);
}

static void	free_sprites(t_controller *con)
{
	mlx_destroy_image(con->vars.mlx, con->sprites->floor);
	mlx_destroy_image(con->vars.mlx, con->sprites->player.sprites[0]);
	mlx_destroy_image(con->vars.mlx, con->sprites->player.sprites[1]);
	mlx_destroy_image(con->vars.mlx, con->sprites->enemy.sprites[0]);
	mlx_destroy_image(con->vars.mlx, con->sprites->enemy.sprites[1]);
}

void	free_all(t_controller *con)
{
	free_map(con);
	free_sprites(con);
	mlx_destroy_window(con->vars.mlx, con->vars.win);
	exit(0);
}

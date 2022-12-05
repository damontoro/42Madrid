/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxFunctions3_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 09:19:08 by dmontoro          #+#    #+#             */
/*   Updated: 2022/12/05 12:01:47 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_player(t_controller *con, int x, int y)
{
	con->game.map.map[con->game.player.y][con->game.player.x] = '0';
	con->game.player.x += x;
	con->game.player.y += y;
	con->game.map.map[con->game.player.y][con->game.player.x] = 'P';
	mlx_put_image_to_window(con->vars.mlx, con->vars.win, con->sprites->floor, \
	(con->game.player.x - x) * SPRITE_SIZE, \
	(con->game.player.y - y) * SPRITE_SIZE);
	mlx_put_image_to_window(con->vars.mlx, con->vars.win, \
	con->sprites->player.sprites[con->sprites->player.curr_frame], \
	con->game.player.x * SPRITE_SIZE, con->game.player.y * SPRITE_SIZE);
}

void	print_sprite(t_controller con, void *sp, int i, int j)
{
	mlx_put_image_to_window(con.vars.mlx, con.vars.win, \
	con.sprites->floor, j * SPRITE_SIZE, i * SPRITE_SIZE);
	mlx_put_image_to_window(con.vars.mlx, con.vars.win, \
	sp, j * SPRITE_SIZE, i * SPRITE_SIZE);
}

int	check_movable(t_map *map, int i, int j)
{
	return (check_boundary(j, i, (*map)) && \
	!ft_strchr("1X", map->map[i][j]));
}

int	check_boundary(int x, int y, t_map map)
{
	if (x < 0 || y < 0 || x >= map.width || y >= map.height)
		return (0);
	return (1);
}

void	update_enemy(t_controller con)
{
	t_list	*tmp;

	if (con.sprites->enemy.time_out > TIMEOUT)
	{
		tmp = con.game.enemies;
		con.sprites->enemy.curr_frame++;
		con.sprites->enemy.curr_frame %= ANIMATION_FRAMES;
		while (tmp != NULL)
		{
			mlx_put_image_to_window(con.vars.mlx, con.vars.win, \
			con.sprites->floor, \
			((t_coords *)tmp->content)->x * SPRITE_SIZE, \
			((t_coords *)tmp->content)->y * SPRITE_SIZE);
			mlx_put_image_to_window(con.vars.mlx, con.vars.win, \
			con.sprites->enemy.sprites \
			[con.sprites->enemy.curr_frame], ((t_coords *)tmp->content)->x \
			* SPRITE_SIZE, ((t_coords *)tmp->content)->y * SPRITE_SIZE);
			tmp = tmp->next;
		}
		con.sprites->enemy.time_out = 0;
	}
	else
		con.sprites->enemy.time_out++;
}

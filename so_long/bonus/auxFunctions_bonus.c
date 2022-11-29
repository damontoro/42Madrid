/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxFunctions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 08:47:25 by dmontoro          #+#    #+#             */
/*   Updated: 2022/11/29 11:22:23 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	move(t_controller *con, int x, int y)
{
	if (check_boundary(con->game.player.x + x, \
	con->game.player.y + y, con->game.map))
	{
		if (con->game.map.map[con->game.player.y + y] \
		[con->game.player.x + x] == '1')
			return (0);
		else if (con->game.map.map[con->game.player.y + y] \
		[con->game.player.x + x] == 'X')
			con->game.win = -1;
		else if (con->game.map.map[con->game.player.y + y] \
		[con->game.player.x + x] == 'E')
		{
			if (con->game.collected_items < con->game.total_items)
				return (0);
			else
				con->game.win = 1;
		}
		else if (con->game.map.map[con->game.player.y + y] \
		[con->game.player.x + x] == 'C')
			con->game.collected_items++;
		move_player(con, x, y);
		return (1);
	}
	return (0);
}

void	update_player(t_controller con)
{
	if (con.sprites->player.time_out > TIMEOUT)
	{
		con.sprites->player.curr_frame++;
		con.sprites->player.curr_frame %= ANIMATION_FRAMES;
		mlx_put_image_to_window(con.vars.mlx, con.vars.win, \
		con.sprites->player.sprites \
		[con.sprites->player.curr_frame], con.game.player.x \
		* SPRITE_SIZE, con.game.player.y * SPRITE_SIZE);
		con.sprites->player.time_out = 0;
	}
	else
		con.sprites->player.time_out++;
}

void	check_path(t_game *game)
{
	t_bfs_aux	d;
	t_list		*aux;

	d.dist = ft_calloc((game->map.height * game->map.width), sizeof(int));
	d.visited = ft_calloc((game->map.height * game->map.width), sizeof(int));
	d.queue = ft_calloc((game->map.height * game->map.width), sizeof(int));
	if (!d.dist || !d.visited || !d.queue)
		ft_error("Error: Error allocating memory");
	d.adj = load_adj(&game->map);
	d.s = game->player.y * game->map.width + game->player.x;
	bfs(d);
	aux = game->items;
	while (aux != NULL)
	{
		if (d.dist[((t_coords *)aux->content)->x + \
		((t_coords *)aux->content)->y * game->map.width] == 0)
			ft_error("Error: Map is not solvable");
		aux = aux->next;
	}
	free_bfs_data(game, d);
}

void	load_game_data(t_game *game, char *filename)
{
	int	i;
	int	j;

	i = 1;
	ft_bzero(game, sizeof(t_game));
	game->map = parse_map(filename);
	while (i < game->map.height - 1)
	{
		j = 1;
		while (j < game->map.width - 1)
		{
			if (game->map.map[i][j] == 'P')
			{
				game->player.x = j;
				game->player.y = i;
			}
			else if (game->map.map[i][j] == 'C')
				ft_lstadd_back(&game->items, ft_lstnew(create_coords(j, i)));
			j++;
		}
		i++;
	}
	game->total_items = ft_lstsize(game->items);
	check_path(game);
}

void	print_map(t_controller con)
{
	int	i;
	int	j;

	i = 0;
	while (i < con.game.map.height)
	{
		j = 0;
		while (j < con.game.map.width)
		{
			if (con.game.map.map[i][j] == '1')
				print_sprite(con, con.sprites->wall, i, j);
			else if (con.game.map.map[i][j] == '0')
				print_sprite(con, con.sprites->floor, i, j);
			else if (con.game.map.map[i][j] == 'P')
				print_sprite(con, con.sprites->player.sprites[0], i, j);
			else if (con.game.map.map[i][j] == 'E')
				print_sprite(con, con.sprites->exit, i, j);
			else if (con.game.map.map[i][j] == 'X')
				print_sprite(con, con.sprites->enemy.sprites[0], i, j);
			else if (con.game.map.map[i][j] == 'C')
				print_sprite(con, con.sprites->item, i, j);
			j++;
		}
		i++;
	}
}

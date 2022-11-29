/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 08:47:53 by dmontoro          #+#    #+#             */
/*   Updated: 2022/11/29 09:47:19 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	key_hook(int keycode, t_controller *con)
{
	if (keycode == 12 || keycode == 53)
	{
		mlx_destroy_window(con->vars.mlx, con->vars.win);
		exit(0);
	}
	else
	{
		if (keycode == 13)
			con->game.move_count += move(con, 0, -1);
		else if (keycode == 0)
			con->game.move_count += move(con, -1, 0);
		else if (keycode == 1)
			con->game.move_count += move(con, 0, 1);
		else if (keycode == 2)
			con->game.move_count += move(con, 1, 0);
	}
	printf("KeyPressed: %d\n", keycode);
	printf("MoveCount: %d\n", con->game.move_count);
	return (0);
}

int	loop_hook(t_controller *con)
{
	if (con->game.win == 1)
	{
		ft_putstr_fd("You Win!\n", 1);
		mlx_destroy_window(con->vars.mlx, con->vars.win);
		exit(0);
	}
	update_player(*con);
	return (0);
}

t_sprites	*load_sprites(t_controller *con)
{
	t_sprites	*ret;
	int			x;

	ret = (t_sprites *)ft_calloc(1, sizeof(t_sprites));
	ret->wall = mlx_xpm_file_to_image(con->vars.mlx, \
	"./assets/wall.xpm", &x, &x);
	ret->exit = mlx_xpm_file_to_image(con->vars.mlx, \
	"./assets/exit.xpm", &x, &x);
	ret->floor = mlx_xpm_file_to_image(con->vars.mlx, \
	"./assets/floor.xpm", &x, &x);
	ret->item = mlx_xpm_file_to_image(con->vars.mlx, \
	"./assets/polla.xpm", &x, &x);
	ft_bzero(ret->player.sprites, sizeof(ret->player.sprites));
	ret->player.sprites[0] = mlx_xpm_file_to_image(con->vars.mlx, \
	"./assets/jiggly.xpm", &x, &x);
	ret->player.sprites[1] = mlx_xpm_file_to_image(con->vars.mlx, \
	"./assets/jiggly2.xpm", &x, &x);
	return (ret);
}

int	main(int argc, char *argv[])
{
	t_controller	con;

	if (argc != 2)
		ft_error("Invalid number of arguments");
	ft_bzero(&con, sizeof(t_controller));
	load_game_data(&con.game, argv[1]);
	if (con.game.map.height * SPRITE_SIZE > MAX_HEIGHT \
	|| con.game.map.width * SPRITE_SIZE > MAX_WIDTH)
		ft_error("Map is too big");
	con.vars.mlx = mlx_init();
	con.vars.win = mlx_new_window(con.vars.mlx, con.game.map.width \
	* SPRITE_SIZE, con.game.map.height * SPRITE_SIZE, "so_long");
	con.sprites = load_sprites(&con);
	print_map(con);
	mlx_loop_hook(con.vars.mlx, loop_hook, &con);
	mlx_hook(con.vars.win, 2, 1L << 0, key_hook, &con);
	mlx_loop(con.vars.mlx);
	return (0);
}

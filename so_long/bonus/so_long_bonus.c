/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:19:00 by dmontoro          #+#    #+#             */
/*   Updated: 2022/12/05 12:09:54 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	destroy_hook(t_controller *con)
{
	free_all(con);
	return (0);
}

int	key_hook(int keycode, t_controller *con)
{
	char	*str;

	if (keycode == 12 || keycode == 53)
		free_all(con);
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
		str = ft_itoa(con->game.move_count);
		mlx_put_image_to_window(con->vars.mlx, \
		con->vars.win, con->sprites->wall, 0, 0);
		mlx_string_put(con->vars.mlx, con->vars.win, 0, 5, 0x00FFFFFF, str);
		free(str);
	}
	printf("Move Count: %d\n", con->game.move_count);
	return (0);
}

int	loop_hook(t_controller *con)
{
	if (con->game.win == 1)
		ft_putstr_fd("You Win!\n", 1);
	else if (con->game.win == -1)
		ft_putstr_fd("You Lose!\n", 1);
	if (con->game.win != 0)
	{
		free_all(con);
	}
	update_player(*con);
	update_enemy(*con);
	return (0);
}

t_sprites	*load_sprites(t_controller *con)
{
	t_sprites	*ret;
	int			x;

	ret = (t_sprites *)ft_calloc(1, sizeof(t_sprites));
	ret->wall = mlx_xpm_file_to_image(con->vars.mlx, \
	"./assets/Tronco.xpm", &x, &x);
	ret->exit = mlx_xpm_file_to_image(con->vars.mlx, \
	"./assets/Salida.xpm", &x, &x);
	ret->floor = mlx_xpm_file_to_image(con->vars.mlx, \
	"./assets/Agua.xpm", &x, &x);
	ret->item = mlx_xpm_file_to_image(con->vars.mlx, \
	"./assets/Piedra.xpm", &x, &x);
	ft_bzero(ret->player.sprites, sizeof(ret->player.sprites));
	ret->player.sprites[0] = mlx_xpm_file_to_image(con->vars.mlx, \
	"./assets/Nutria.xpm", &x, &x);
	ret->player.sprites[1] = mlx_xpm_file_to_image(con->vars.mlx, \
	"./assets/Nutria2.xpm", &x, &x);
	ft_bzero(ret->enemy.sprites, sizeof(ret->enemy.sprites));
	ret->enemy.sprites[0] = mlx_xpm_file_to_image(con->vars.mlx, \
	"./assets/Cocodrilo.xpm", &x, &x);
	ret->enemy.sprites[1] = mlx_xpm_file_to_image(con->vars.mlx, \
	"./assets/Cocodrilo2.xpm", &x, &x);
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
	free_ini_sprites(&con);
	mlx_hook(con.vars.win, 17, 0L, destroy_hook, &con);
	mlx_loop_hook(con.vars.mlx, loop_hook, &con);
	mlx_hook(con.vars.win, 2, 1L << 0, key_hook, &con);
	mlx_loop(con.vars.mlx);
	return (0);
}

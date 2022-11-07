#include "functions.h"

int	key_hook(int keycode, t_controller *con)
{
	char	*str;

	if (keycode == 65307 || keycode == 113)
	{
		mlx_destroy_window(con->vars.mlx, con->vars.win);
		exit(0);
	}
	else{
		if(keycode == 119)//w
			con->game.moveCount += move(con, 0, -1);
		else if(keycode == 97)//a
			con->game.moveCount += move(con, -1, 0);
		else if(keycode == 115)//s
			con->game.moveCount += move(con, 0, 1);
		else if(keycode == 100)//d
			con->game.moveCount += move(con, 1, 0);
		str = ft_itoa(con->game.moveCount);
		mlx_put_image_to_window(con->vars.mlx, con->vars.win, con->sprites->wall, 0, 0);
		mlx_string_put(con->vars.mlx, con->vars.win, 5, 20, 0x00FFFFFF, str);
		free(str);
	}
	printf("KeyPressed: %d\n", keycode);
	printf("MoveCount: %d\n", con->game.moveCount);
	return (0);
}

int loop_hook(t_controller *con)
{
	if (con->game.win == 1)
	{
		ft_putstr_fd("You Win!\n", 1);
		mlx_destroy_window(con->vars.mlx, con->vars.win);
		exit(0);
	}
	else if (con->game.win == -1)
	{
		ft_putstr_fd("You Lose!\n", 1);
		mlx_destroy_window(con->vars.mlx, con->vars.win);
		exit(0);
	}
	updatePlayer(*con);
	//updateEnemies();
}

t_sprites *loadSprites(t_controller *con)
{
	t_sprites	*ret;
	int			x;

	ret = (t_sprites *)ft_calloc(1, sizeof(t_sprites));
	ret->wall = mlx_xpm_file_to_image(con->vars.mlx, "./assets/wall.xpm", &x, &x);
	ret->exit = mlx_xpm_file_to_image(con->vars.mlx, "./assets/exit.xpm", &x, &x);
	ret->floor = mlx_xpm_file_to_image(con->vars.mlx, "./assets/floor.xpm", &x, &x);
	ret->item = mlx_xpm_file_to_image(con->vars.mlx, "./assets/polla.xpm", &x, &x);
	ft_bzero(ret->player.sprites, sizeof(ret->player.sprites));
	ret->player.sprites[0] = mlx_xpm_file_to_image(con->vars.mlx, "./assets/jiggly.xpm", &x, &x);
	ret->player.sprites[1] = mlx_xpm_file_to_image(con->vars.mlx, "./assets/jiggly2.xpm", &x, &x);
	return (ret);
}

int main(int argc, char *argv[])
{
	t_controller con;

	if (argc != 2)
		ft_error("Invalid number of arguments");
	ft_bzero(&con, sizeof(t_controller));
	loadGameData(&con.game, argv[1]);
	con.vars.mlx = mlx_init();
	con.vars.win = mlx_new_window(con.vars.mlx, con.game.map.width * 32, con.game.map.height * 32, "so_long");
	con.sprites = loadSprites(&con);

	printMap(con);
	mlx_loop_hook(con.vars.mlx, loop_hook, &con);
	mlx_key_hook(con.vars.win, key_hook, &con);
	mlx_loop(con.vars.mlx);
	return (0);
}
#include "so_long.h"


int	key_hook(int keycode, t_controller *con)
{
	if(keycode == 65307 || keycode == 113){
		mlx_destroy_window(con->vars.mlx, con->vars.win);
		exit(0);
	}
	//else
		//printMap(&con->game->map, &con->sprites, &con->vars);

	printf("KeyPressed: %d\n", keycode);
	return (0);
}

int main(int argc, char *argv[])
{

	t_controller con;
	t_game game;

	game.map = parseMap(argv[1]);
	con.vars.mlx = mlx_init();
	con.vars.win = mlx_new_window(con.vars.mlx, game.map.width * 32, game.map.height * 32, "Primera ventana");
	con.game = &game;

	int x = 0;
	con.sprites->player = mlx_new_image(con.vars.mlx, 32, 32);
	printf("Aqui he llegado1\n");
	con.sprites->player = mlx_xpm_file_to_image(con.vars.mlx, "imgs/jiggly.xpm", &x, &x);
	printf("Aqui he llegado2\n");

	con.sprites->wall = mlx_new_image(con.vars.mlx, 32, 32);
	con.sprites->wall = mlx_xpm_file_to_image(con.vars.mlx, "imgs/wall.xpm", &x, &x);
	con.sprites->exit = mlx_new_image(con.vars.mlx, 32, 32);
	con.sprites->exit = mlx_xpm_file_to_image(con.vars.mlx, "imgs/exit.xpm", &x, &x);
	

	con.sprites->floor = mlx_new_image(con.vars.mlx, 32, 32);
	con.sprites->floor = mlx_xpm_file_to_image(con.vars.mlx, "imgs/placeholder.xpm", &x, &x);
	con.sprites->enemy = mlx_new_image(con.vars.mlx, 32, 32);
	con.sprites->enemy = mlx_xpm_file_to_image(con.vars.mlx, "imgs/placeholder.xpm", &x, &x);
	con.sprites->collectible = mlx_new_image(con.vars.mlx, 32, 32);
	con.sprites->collectible = mlx_xpm_file_to_image(con.vars.mlx, "imgs/placeholder.xpm", &x, &x);


	printf("Aqui he llegado3\n");
	printMap(&game.map, con.sprites, &con.vars);
	mlx_key_hook(con.vars.win, key_hook, &con);
	mlx_loop(con.vars.mlx);
	
	return (0);
}
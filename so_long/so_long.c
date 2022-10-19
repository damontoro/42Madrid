#include "so_long.h"


int	key_hook(int keycode, t_controller *con)
{
	if(keycode == 65307 || keycode == 113){
		mlx_destroy_window(con->vars.mlx, con->vars.win);
		exit(0);
	}
	else{
		
		if(keycode == 119)//w
			printf("ARRIBA\n");
			//moveUp(con);
		else if(keycode == 97)//a
			printf("IZQUIERDA\n");
			//moveLeft(con);
		else if(keycode == 115)//s
			printf("ABAJO\n");
			//moveDown(con);
		else if(keycode == 100)//d
			printf("DERECHA\n");
			//moveRight(con);
		printMap(*con);
	}
	printf("KeyPressed: %d\n", keycode);
	return (0);
}

t_sprites *loadSprites(t_controller *con)
{
	t_sprites	*ret;
	int			x;

	ret = (t_sprites *)malloc(sizeof(t_sprites));
	ret->wall = mlx_xpm_file_to_image(con->vars.mlx, "./assets/wall.xpm", &x, &x);
	ret->exit = mlx_xpm_file_to_image(con->vars.mlx, "./assets/exit.xpm", &x, &x);
	ret->floor = mlx_xpm_file_to_image(con->vars.mlx, "./assets/placeholder.xpm", &x, &x);
	ret->item = mlx_xpm_file_to_image(con->vars.mlx, "./assets/jiggly2.xpm", &x, &x);
	(*con).game.player.sprites[0] = mlx_xpm_file_to_image(con->vars.mlx, "./assets/jiggly.xpm", &x, &x);
	(*con).game.player.sprites[1] = mlx_xpm_file_to_image(con->vars.mlx, "./assets/jiggly2.xpm", &x, &x);
	return (ret);
}

int main(int argc, char *argv[])
{
	t_controller con;
	ft_bzero(&con, sizeof(t_controller));
	con.game.map = parseMap(argv[1]);
	con.vars.mlx = mlx_init();
	con.vars.win = mlx_new_window(con.vars.mlx, con.game.map.width * 32, con.game.map.height * 32, "Primera ventana");
	con.sprites = loadSprites(&con);

	printMap(con);
	mlx_key_hook(con.vars.win, key_hook, &con);
	mlx_loop(con.vars.mlx);
	
	return (0);
}
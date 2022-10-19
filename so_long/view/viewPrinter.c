#include "view.h"

void printMap(t_controller con){
	for(int i = 0; i < con.game.map.height; i++){
		for(int j = 0; j < con.game.map.width; j++){
			if (con.game.map.map[i][j] == '1')
				mlx_put_image_to_window(con.vars.mlx, con.vars.win, con.sprites->wall, j * 32, i * 32);
			else if (con.game.map.map[i][j] == '0')
				mlx_put_image_to_window(con.vars.mlx, con.vars.win, con.sprites->floor, j * 32, i * 32);
			else if (con.game.map.map[i][j] == 'P')
				mlx_put_image_to_window(con.vars.mlx, con.vars.win, con.game.player.sprites[con.game.player.animFrame], j * 32, i * 32);
			else if (con.game.map.map[i][j] == 'E')
				mlx_put_image_to_window(con.vars.mlx, con.vars.win, con.sprites->exit, j * 32, i * 32);
			else if (con.game.map.map[i][j] == 'X')
				mlx_put_image_to_window(con.vars.mlx, con.vars.win, con.game.player.sprites[1], j * 32, i * 32);
			else if (con.game.map.map[i][j] == 'C')
				mlx_put_image_to_window(con.vars.mlx, con.vars.win, con.sprites->item, j * 32, i * 32);
		}
	}
}
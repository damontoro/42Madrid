#include "view.h"

void printMap(t_map *map, t_sprites *sprites, t_vars *vars){
	for(int i = 0; i < map->height; i++){
		for(int j = 0; j < map->width; j++){
			if (map->map[i][j] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, sprites->wall, j * 32, i * 32);
			else if (map->map[i][j] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win, sprites->floor, j * 32, i * 32);
			else if (map->map[i][j] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win, sprites->player, j * 32, i * 32);
			else if (map->map[i][j] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, sprites->exit, j * 32, i * 32);
			else if (map->map[i][j] == 'X')
				mlx_put_image_to_window(vars->mlx, vars->win, sprites->enemy, j * 32, i * 32);
			else if (map->map[i][j] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, sprites->item, j * 32, i * 32);
		}
	}
}
#ifndef VIEW_H
# define VIEW_H

# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>
# include<fcntl.h>
# include "../types.h"
# include"../libs/libft/libft.h"
# include"../utils/utils.h"
# include"../libs/mlx-linux/mlx.h"


t_map	parseMap(char *fileName);
int		checkMapForm(int fd);
char	**loadMap(int fd, int size, int *width);
void	printMap(t_map *map, t_sprites *sprites, t_vars *vars);

# endif
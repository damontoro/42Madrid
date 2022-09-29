
#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>


void	*mlx_init();
void	*mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
int	mlx_clear_window(void *mlx_ptr, void *win_ptr);
int	mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);


# endif
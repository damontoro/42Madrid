#ifndef DEFS_H
# define DEFS_H

# include "libs/libft/libft.h"
# include "libs/mlx-linux/mlx.h"
# include "libs/libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

# ifndef MAP_CHARS
#  define MAP_CHARS "10CEPX"
# endif

#ifndef WINDOW_WIDTH
# define WINDOW_WIDTH 800
#endif

#ifndef WINDOW_HEIGHT
# define WINDOW_HEIGHT 600
#endif

#ifndef ANIMATION_FRAMES
# define ANIMATION_FRAMES 2
#endif

#ifndef TIMEOUT
# define TIMEOUT 5000
#endif

#ifndef CHECK_BOUNDARY
# define CHECK_BOUNDARY(x, y, map) (x >= 0 && x < map.width && y >= 0 && y < map.height)
#endif

typedef struct s_coords
{
	int	x;
	int	y;
}	t_coords;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_map {

	char	**map;
	int		height;
	int		width;

}	t_map;

typedef struct s_animation {

	void	*sprites[ANIMATION_FRAMES];
	int		currFrame;
	int		timeOut;

} t_animation;

typedef struct s_game {

	t_map	map;
	t_list	*enemy;
	t_list	*items;

	int		totalItems;
	int		collectedItems;
	int		moveCount;
	int		win;

	t_coords player;
	
}	t_game;

typedef struct s_sprites {

	void	*wall;
	void	*floor;
	void	*exit;
	void	*item;
	t_animation player;
	t_animation enemy;
	
}	t_sprites;

typedef struct s_controller {

	t_vars	vars;
	t_game	game;
	t_sprites *sprites;
	
}	t_controller;

typedef struct s_content {

	int	collectibles;
	int	player;
	int exit;
	int enemies;

}	t_content;

#endif
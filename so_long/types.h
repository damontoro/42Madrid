#ifndef TYPES_H
# define TYPES_H

# include "libs/libft/libft.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_map {

	char	**map;
	int		height;
	int		width;

}	t_map;

typedef struct s_game {

	t_map	map;
	t_list	collectibles;
	t_list enemy;
	//t_entity player;
	
}	t_game;

typedef struct s_sprites {

	void	*wall;
	void	*floor;
	void	*exit;
	void	*enemy;
	void	*player;
	void	*item;
	
}	t_sprites;

typedef struct s_controller {

	t_vars	vars;
	t_game	*game;
	t_sprites *sprites;
	
}	t_controller;

typedef struct s_content {

	int	collectibles;
	int	player;
	int exit;
	int enemies;

}	t_content;

#endif
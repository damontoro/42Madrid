#ifndef TYPES_H
# define TYPES_H

typedef struct s_map {

	char	**map;
	int		length;
	int		width;

}	t_map;

typedef struct s_content {

	int	collectibles;
	int	player;
	int exit;
	int enemies;

}	t_content;

#endif
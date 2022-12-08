/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 08:47:31 by dmontoro          #+#    #+#             */
/*   Updated: 2022/12/08 13:20:31 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H

# include "libs/libft/libft.h"
# include <mlx.h>
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
#  define MAP_CHARS "10CEP"
# endif

# ifndef MAX_HEIGHT
#  define MAX_HEIGHT 2880
# endif

# ifndef MAX_WIDTH
#  define MAX_WIDTH 5120
# endif

# ifndef SRITE_SIZE
#  define SPRITE_SIZE 64
# endif

# ifndef ANIMATION_FRAMES
#  define ANIMATION_FRAMES 2
# endif

# ifndef TIMEOUT
#  define TIMEOUT 5000
# endif

typedef struct s_coords
{
	int	x;
	int	y;
}	t_coords;

typedef struct s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_map {
	char	**map;
	int		height;
	int		width;
}	t_map;

typedef struct s_animation {
	void	*sprites[ANIMATION_FRAMES];
	int		curr_frame;
	int		time_out;
}	t_animation;

typedef struct s_game {
	t_map		map;
	t_list		*items;
	int			total_items;
	int			collected_items;
	int			move_count;
	int			win;
	t_coords	player;
}	t_game;

typedef struct s_sprites {
	void		*wall;
	void		*floor;
	void		*exit;
	void		*item;
	t_animation	player;
}	t_sprites;

typedef struct s_controller {
	t_vars		vars;
	t_game		game;
	t_sprites	*sprites;
}	t_controller;

typedef struct s_bfs_aux {
	int	s;
	int	*dist;
	int	*visited;
	int	**adj;
	int	*queue;
}	t_bfs_aux;

typedef struct s_content {
	int	collectibles;
	int	player;
	int	exit;
}	t_content;

#endif
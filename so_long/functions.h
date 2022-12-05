/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 08:47:37 by dmontoro          #+#    #+#             */
/*   Updated: 2022/12/05 12:12:59 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "./defs.h"

void		bfs(t_bfs_aux data);
int			check_boundary(int x, int y, t_map map);
t_coords	*create_coords(int x, int y);
int			**load_adj(t_map *map);
void		free_bfs_data(t_game *game, t_bfs_aux d);
void		print_sprite(t_controller con, void *sp, int i, int j);
void		free_ini_sprites(t_controller *con);
void		free_all(t_controller *con);

char		*get_next_line(int fd);
size_t		ft_strlen_gnl(const char *s);
char		*ft_strjoin_gnl(char *s1, const char *s2);
char		*ft_strdup_gnl(const char *s1);
char		*ft_strchr_gnl(const char *s, int c);

void		update_player(t_controller con);
void		move_player(t_controller *con, int x, int y);
int			move(t_controller *con, int x, int y);
void		load_game_data(t_game *game, char *filename);
void		ft_error(char *str);
t_map		parse_map(char *fileName);
int			check_map_form(int fd);
char		**load_map(int fd, int size, int *width);
void		print_map(t_controller con);

#endif
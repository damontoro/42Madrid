/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxFunctions2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 08:47:28 by dmontoro          #+#    #+#             */
/*   Updated: 2022/11/29 11:11:54 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_coords	*create_coords(int x, int y)
{
	t_coords	*ret;

	ret = malloc(sizeof(t_coords));
	ret->x = x;
	ret->y = y;
	return (ret);
}

void	free_bfs_data(t_game *game, t_bfs_aux data)
{
	int	i;

	i = 0;
	ft_lstclear(&game->items, free);
	free(data.dist);
	free(data.visited);
	free(data.queue);
	while (i < game->map.height * game->map.width + 1)
		free(data.adj[i++]);
	free(data.adj);
}

void	load_adj_data(int **ret, t_map *map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			k = 0;
			ft_memset(ret[i * map->width + j], -1, 5 * sizeof(int));
			if (check_movable(map, i + 1, j))
				ret[i * map->width + j][k++] = ((i + 1) * map->width + j);
			if (check_movable(map, i - 1, j))
				ret[i * map->width + j][k++] = ((i - 1) * map->width + j);
			if (check_movable(map, i, j + 1))
				ret[i * map->width + j][k++] = (i * map->width + j + 1);
			if (check_movable(map, i, j - 1))
				ret[i * map->width + j][k++] = (i * map->width + j - 1);
			j++;
		}
		i++;
	}
}

int	**load_adj(t_map *map)
{
	int	**ret;
	int	i;

	i = 0;
	ret = malloc(sizeof(int *) * (map->height * map->width + 1));
	if (!ret)
		ft_error("Problem Allocating memory");
	ret[map->height * map->width] = NULL;
	while (i < map->height * map->width)
	{
		ret[i] = malloc(5 * sizeof(int));
		if (!ret[i])
			ft_error("Problem Allocating memory");
		i++;
	}
	load_adj_data(ret, map);
	return (ret);
}

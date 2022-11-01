#include "defs.h"
#include "functions.h"

t_coords	*createCoords(int x, int y)
{
	t_coords	*ret;

	ret = malloc(sizeof(t_coords));
	ret->x = x;
	ret->y = y;
	return (ret);
}

void freeBfsData(t_game *game, int* dist, int *visited, int *queue, int **adj)
{
	int	i;

	i = 0;
	ft_lstclear(&game->items, free);
	free(dist);
	free(visited);
	free(queue);
	while (i < game->map.height * game->map.width + 1)
		free(adj[i++]);
	free(adj);
}

void loadAdjData(int **ret, t_map *map)
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
			ft_memset(ret[i  * map->width + j], -1, 5 * sizeof(int));
			if (CHECK_BOUNDARY(j, i + 1, (*map)) && map->map[i + 1][j] != '1')
				ret[i * map->width + j][k++] = ((i + 1) * map->width + j);
			if (CHECK_BOUNDARY(j, i - 1, (*map)) && map->map[i - 1][j] != '1')
				ret[i * map->width + j][k++] = ((i - 1) * map->width + j);
			if (CHECK_BOUNDARY(j + 1, i, (*map)) && map->map[i][j + 1] != '1')
				ret[i * map->width + j][k++] = (i * map->width + j + 1);
			if (CHECK_BOUNDARY(j - 1, i, (*map)) && map->map[i][j - 1] != '1')
				ret[i * map->width + j][k++] = (i * map->width + j - 1);
			j++;
		}
		i++;
	}
}

int	**loadAdj(t_map *map)
{
	int **ret;
	int		i;

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
	loadAdjData(ret, map);
	return (ret);
}
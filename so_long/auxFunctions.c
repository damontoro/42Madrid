#include "functions.h"

int move(t_controller *con, int x, int y)
{
	if (CHECK_BOUNDARY(con->game.player.x + x, con->game.player.y + y, con->game.map))
	{
		if (con->game.map.map[con->game.player.y + y][con->game.player.x + x] == '1')
			return (0);
		if (con->game.map.map[con->game.player.y + y][con->game.player.x + x] == 'E')
			if (con->game.collectedItems < con->game.totalItems)
				return (0);
			else
				con->game.win = 1;
		if (con->game.map.map[con->game.player.y + y][con->game.player.x + x] == 'X')
			con->game.win = -1;
		if(con->game.map.map[con->game.player.y + y][con->game.player.x + x] == 'C')
			con->game.collectedItems++;
		con->game.map.map[con->game.player.y][con->game.player.x] = '0';
		con->game.player.x += x;
		con->game.player.y += y;
		con->game.map.map[con->game.player.y][con->game.player.x] = 'P';
		mlx_put_image_to_window(con->vars.mlx, con->vars.win, con->sprites->floor, (con->game.player.x - x) * 32, (con->game.player.y - y) * 32);
		mlx_put_image_to_window(con->vars.mlx, con->vars.win, 
							con->sprites->player.sprites[con->sprites->player.currFrame], con->game.player.x * 32, con->game.player.y * 32);
		return (1);
	}
	return (0);
}

void updatePlayer(t_controller con)
{
	if (con.sprites->player.timeOut > TIMEOUT){
		con.sprites->player.currFrame++;
		con.sprites->player.currFrame %= ANIMATION_FRAMES;
		mlx_put_image_to_window(con.vars.mlx, con.vars.win, 
							con.sprites->player.sprites[con.sprites->player.currFrame], con.game.player.x * 32, con.game.player.y * 32);
		con.sprites->player.timeOut = 0;
	}
	else
		con.sprites->player.timeOut++;
}

void checkPath(t_game *game)
{
	int	*dist;
	int	*visited;
	int	*queue;
	int	**adj;
	t_list *aux;

	dist = ft_calloc((game->map.height * game->map.width), sizeof(int));
	visited = ft_calloc((game->map.height * game->map.width), sizeof(int));
	queue = ft_calloc((game->map.height * game->map.width), sizeof(int));
	if (!dist || !visited || !queue)
		ft_error("Error allocating memory");
	adj = loadAdj(&game->map);
	bfs(game->player.x + game->player.y * game->map.width, dist, visited, adj, queue);
	aux = game->items;
	while (aux != NULL)
	{
		if (dist[((t_coords *)aux->content)->x + ((t_coords *)aux->content)->y * game->map.width] == 0)
			ft_error("Map is not solvable");
		aux = aux->next;
	}
	freeBfsData(game, dist, visited, queue, adj);
}

void loadGameData(t_game *game, char *filename)
{
	int	i;
	int	j;

	i = 1;
	ft_bzero(game, sizeof(t_game));
	game->map = parseMap(filename);
	while (i < game->map.height - 1)
	{
		j = 1;
		while (j < game->map.width - 1)
		{
			if (game->map.map[i][j] == 'P')
			{
				game->player.x = j;
				game->player.y = i;
			}
			else if (game->map.map[i][j] == 'C')
				ft_lstadd_back(&game->items, ft_lstnew(createCoords(j, i)));
			j++;
		}
		i++;
	}
	game->totalItems = ft_lstsize(game->items);
	checkPath(game);
}

void printMap(t_controller con){
	for(int i = 0; i < con.game.map.height; i++){
		for(int j = 0; j < con.game.map.width; j++){
			if (con.game.map.map[i][j] == '1')
				mlx_put_image_to_window(con.vars.mlx, con.vars.win, con.sprites->wall, j * 32, i * 32);
			else if (con.game.map.map[i][j] == '0')
				mlx_put_image_to_window(con.vars.mlx, con.vars.win, con.sprites->floor, j * 32, i * 32);
			else if (con.game.map.map[i][j] == 'P')
				mlx_put_image_to_window(con.vars.mlx, con.vars.win, 
						con.sprites->player.sprites[0], j * 32, i * 32);
			else if (con.game.map.map[i][j] == 'E')
				mlx_put_image_to_window(con.vars.mlx, con.vars.win, con.sprites->exit, j * 32, i * 32);
			else if (con.game.map.map[i][j] == 'X')
				mlx_put_image_to_window(con.vars.mlx, con.vars.win, con.sprites->item, j * 32, i * 32);
			else if (con.game.map.map[i][j] == 'C')
				mlx_put_image_to_window(con.vars.mlx, con.vars.win, con.sprites->item, j * 32, i * 32);
		}
	}
}
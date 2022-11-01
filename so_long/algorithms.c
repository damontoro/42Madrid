#include "defs.h"
#include "functions.h"

void bfs(int s, int *dist, int *visited, int **adj, int *queue)
{
	int	i;
	int	last;
	int	j;

	i = 0;
	last = 0;
	queue[last++] = s;
	dist[s] = 0;
	visited[s] = 1;
	while (i < last)
	{
		j = 0;
		while (adj[queue[i]][j] != -1)
		{
			if(!visited[adj[queue[i]][j]])
			{
				dist[adj[queue[i]][j]] = dist[queue[i]] + 1;
				visited[adj[queue[i]][j]] = 1;
				queue[last++] = adj[queue[i]][j];
			}
			j++;
		}
		i++;
	}
}

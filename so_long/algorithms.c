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

/*
SACADO DE MIS APUNTES DE PCOM
devuelve el coste de ir desde pos al origen (el vértice 0)
pasando por todos los vértices no visitados (con un bit a 0)
V vértices del grafo completo
dist matriz de adyacencia del grafo
memo tabla de DP
*/
int tsp(int pos, int visitados, int V, int **dist, int **memo) {
	if (visitados == (1 << V) - 1) // hemos visitado ya todos los vértices
		return dist[pos][0]; // volvemos al origen
	if (memo[pos][visitados] != -1)
		return memo[pos][visitados];
	int res = 1000000000; // INF
	for (int i = 1; i < V; ++i)
		if (!(visitados & (1 << i))) // no hemos visitado vértice i
	res = min(res, dist[pos][i] + tsp(i, visitados | (1 << i), V, dist, memo));
	return memo[pos][visitados] = res;
}
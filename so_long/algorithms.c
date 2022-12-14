/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 08:47:22 by dmontoro          #+#    #+#             */
/*   Updated: 2022/11/29 09:17:17 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"
#include "functions.h"

void	bfs(t_bfs_aux data)
{
	int	i;
	int	last;
	int	j;

	i = 0;
	last = 0;
	data.queue[last++] = data.s;
	data.dist[data.s] = 0;
	data.visited[data.s] = 1;
	while (i < last)
	{
		j = 0;
		while (data.adj[data.queue[i]][j] != -1)
		{
			if (!data.visited[data.adj[data.queue[i]][j]])
			{
				data.dist[data.adj[data.queue[i]][j]] \
				= data.dist[data.queue[i]] + 1;
				data.visited[data.adj[data.queue[i]][j]] = 1;
				data.queue[last++] = data.adj[data.queue[i]][j];
			}
			j++;
		}
		i++;
	}
}

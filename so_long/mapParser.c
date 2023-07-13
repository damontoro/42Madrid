/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapParser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 08:47:51 by dmontoro          #+#    #+#             */
/*   Updated: 2023/06/15 18:36:57 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

static int	check_content_line(char *line, int pos, int length)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(line);
	while (i < size - 1)
	{
		if ((pos == 0 || pos == length) && line[i] != '1')
			return (0);
		if (!ft_strchr(MAP_CHARS, line[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_map_form(int fd)
{
	int		i;
	size_t	size;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (i == 0)
			size = ft_strlen(line);
		else if (size != (ft_strlen(line) + \
				!(line[ft_strlen(line) - 1] == '\n')))
			ft_error("Error: Map is not rectangular");
		if (!check_content_line(line, i, 0))
			ft_error("Error: Invalid character in map");
		if (line[0] != '1' || line[size - 2] != '1')
			ft_error("Error: Map is not closed");
		free(line);
		line = get_next_line(fd);
		i++;
	}
	return (i);
}

char	**load_map(int fd, int size, int *width)
{
	char	**map;
	int		i;

	i = 0;
	map = (char **) malloc(sizeof(char *) * (size + 1));
	if (size == 0)
		ft_error("Error: Map is empty");
	if (!map)
		ft_error("Error: Problems with memory allocation");
	while (i < size)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			ft_error("Error: Problem while loading the map");
		i++;
	}
	map[size] = NULL;
	*width = ft_strlen(map[0]) - 1;
	return (map);
}

void	check_map_content(t_map map)
{
	int			i;
	int			j;
	t_content	content;

	ft_bzero(&content, sizeof(t_content));
	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			if (map.map[i][j] == 'P')
				content.player++;
			else if (map.map[i][j] == 'C')
				content.collectibles++;
			else if (map.map[i][j] == 'E')
				content.exit++;
			j++;
		}
		i++;
	}
	if (content.player != 1 || content.exit != 1 || content.collectibles < 1)
		ft_error("Error: Invalid map content");
}

t_map	parse_map(char *fileName)
{
	int		fd;
	t_map	map;

	if (ft_strncmp(ft_strrchr(fileName, '.'), ".ber", 4))
		ft_error("Error: Invalid file extension");
	fd = open(fileName, O_RDONLY);
	if (fd < 0)
		ft_error("Error: Invalid file");
	map.height = check_map_form(fd);
	close(fd);
	fd = open(fileName, O_RDONLY);
	if (fd < 0)
		ft_error("Error: Invalid file");
	map.map = load_map(fd, map.height, &map.width);
	if (!check_content_line(map.map[map.height - 1], map.height, map.height))
		ft_error("Error: Map is not closed");
	check_map_content(map);
	close(fd);
	return (map);
}

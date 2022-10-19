#include "../functions.h"

static int	checkContentLine(char *line, int pos, int length)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(line);
	while (i < size - 1)
	{
		if((pos == 0 || pos == length) && line[i] != '1')
			return (0);
		if (!ft_strchr(MAP_CHARS, line[i]))
			return (0);
		i++;
	}
	if(line[size - 1] != '\n')
		return (0);
	return (1);
}

int	checkMapForm(int fd)
{
	int	i;
	int	size;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while(line != NULL)
	{
		if (i == 0)
			size = ft_strlen(line);
		else if (size != ft_strlen(line))
			ft_error("Error\nMap is not rectangular");
		if (!checkContentLine(line, i, 0))
			ft_error("Error\nInvalid character in map");
		if (line[0] != '1' || line[size - 2] != '1')
			ft_error("Error\nMap is not closed");
		free(line);
		line = get_next_line(fd);
		i++;
	}
	return (i);
}

char	**loadMap(int fd, int size, int *width)
{
	char	**map;
	int		i;

	i = 0;
	map = (char **)malloc(sizeof(char *) * (size + 1));
	if (!map)
		ft_error("Error\nProblems with memory allocation");
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

void checkMapContent(t_map map)
{
	int	i;
	int j;
	t_content content;

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
			else if (map.map[i][j] == 'X')
				content.enemies++;
			j++;
		}
		i++;
	}
	if (content.player != 1 || content.exit != 1 || content.collectibles < 1)
		ft_error("Error\nInvalid map content");
}

t_map	parseMap(char *fileName)
{
	int fd;
	t_map map;
	
	if(ft_strncmp(ft_strrchr(fileName,'.'), ".ber", 4))
		ft_error("Error\nInvalid file extension");
	fd = open(fileName, O_RDONLY);
	if(fd < 0)
		ft_error("Error:\nInvalid file");
	map.height = checkMapForm(fd);
	close(fd);
	fd = open(fileName, O_RDONLY);
	if(fd < 0)
		ft_error("Error:\nInvalid file");
	map.map = loadMap(fd, map.height, &map.width);
	if (!checkContentLine(map.map[map.height - 1], map.height, map.height))
			ft_error("Error\nMap is not closed");
	checkMapContent(map);
	close(fd);
	return (map);
}
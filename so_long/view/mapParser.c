#include "view.h"

char	*parseMap(char *fileName)
{
	char **map;
	int fd;
	
	if(ft_strncmp(ft_strrchr(fileName,'.'), ".ber", 4))
	{
		perror("Error\nInvalid file extension");
		exit(EXIT_FAILURE);
	}
	fd = open(fileName, O_RDONLY);
	if(fd < 0)
	{
		perror("Error\nInvalid file");
		exit(EXIT_FAILURE);
	}
	checkMapForm(fd);
	//checkMapContent();

	return (ft_strdup("todo bien"));
}

static int checkBorderLine(char	*line)
{
	int i;

	i = 0;
	while(line[i] && line[i] != '\n')
	{
		if(line[i] != '1'){
			return (0);
		}
		i++;
	}
	return (1);
}

void	checkMapForm(int fd)
{
	int	i;
	char	*line;

	i = 0;
	while((line = get_next_line(fd)) != NULL)
	{
		if(i == 0){
			if(!checkBorderLine(line))
			{
				perror("Error1: map is not closed\n");
				exit(EXIT_FAILURE);
			}
		}
		if (!line[0] == '1' || !line[ft_strlen(line) - 1] == '1')
		{
			perror("Error2: map is not closed\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

char	**loadMap(char *fileName)
{
	int		fd;
	char	**map;
	char	*line;

	fd = open(fileName, O_RDONLY);
	if (fd > 0)
	{
		line = get_next_line(fd);
	}
	close(fd);
	return (map);
}
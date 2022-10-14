#ifndef VIEW_H
# define VIEW_H

# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>
# include<fcntl.h>
# include"../libs/libft/libft.h"
# include"../utils/get_next_line.h"


char	*parseMap(char *fileName);
void	checkMapForm(int fd);
char	**loadMap(char *fileName);

# endif
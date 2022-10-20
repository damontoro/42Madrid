
# include"./defs.h"

char	*get_next_line(int fd);
size_t	ft_strlen_gnl(const char *s);
char	*ft_strjoin_gnl(char *s1, const char *s2);
char	*ft_strdup_gnl(const char *s1);
char	*ft_strchr_gnl(const char *s, int c);

void	updatePlayer(t_controller con);
int		move(t_controller *con, int x, int y);
void	loadGameData(t_game *game, char *filename);
void	ft_error(char *str);
t_map	parseMap(char *fileName);
int		checkMapForm(int fd);
char	**loadMap(int fd, int size, int *width);
void	printMap(t_controller con);
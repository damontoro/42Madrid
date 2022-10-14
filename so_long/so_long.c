#include "so_long.h"

int main(int argc, char *argv[])
{
	void	*ini;
	void	*window;

	//ini = mlx_init();
	//window = mlx_new_window(ini, 600, 400, "Primera ventana");
	//printf("%d\n", ft_strncmp(ft_strrchr(argv[1],'.'), ".ber", 4));

	printf("%s\n", parseMap(argv[1]));
	//mlx_loop(ini);
	

	return (0);
}
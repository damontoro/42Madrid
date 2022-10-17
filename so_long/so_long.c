#include "so_long.h"

int main(int argc, char *argv[])
{
	void	*ini;
	void	*window;

	//ini = mlx_init();
	//window = mlx_new_window(ini, 600, 400, "Primera ventana");
	//printf("%d\n", ft_strncmp(ft_strrchr(argv[1],'.'), ".ber", 4));
	t_map mapa = parseMap(argv[1]);
	for(int i = 0; i < mapa.length; i++){
		printf("%s", mapa.map[i]);
		free(mapa.map[i]);
	}
	free(mapa.map);
	//mlx_loop(ini);
	

	return (0);
}
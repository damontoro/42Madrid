#include "so_long.h"

int main(int argc, char *argv[])
{
	void	*ini;
	void	*window;

	ini = mlx_init();
	window = mlx_new_window(ini, 600, 400, "Primera ventana");
	printf("%s\n%s\n", "Todo funciona", ft_strdup("SIUUU"));
	mlx_loop(ini);
	

	return (0);
}
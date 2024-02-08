#include "fractol.h"
#define MAX_ITER 100


int	main(int argc, char **argv)
{
	void	*mlx;
	int ancho = 800;
	int largo = 800;

	mlx = mlx_init();

	void *win = mlx_new_window(mlx, ancho, largo, "title");
	int dimensiones[] = {ancho, largo};
	t_fractal fractal;
	fractal.name = "Julia";
	//draw_julia(mlx, win, -0.7, 0.27015, dimensiones);



	mlx_loop(mlx);
}

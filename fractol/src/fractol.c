#include "fractol.h"


void choose_fractal(t_fractal *fractal)
{
	fractal -> mlx = mlx_init();
	fractal -> win = mlx_new_window(fractal -> mlx, WIDTH, HEIGHT, fractal -> name);
	fractal -> max_iter = 100;
	if (ft_strncmp("Julia", fractal -> name, 6) == 0)
	{
		fractal -> cr = -0.7;
		fractal -> ci = 0.27015;
		draw_julia(fractal);
	}
	
}

int main(int argc, char **argv)
{
	
	void	*mlx;
	t_fractal fractal;
	
	fractal.name = argv[1];
	choose_fractal(&fractal);

	//mlx = mlx_init();

	//void *win = mlx_new_window(mlx, ancho, largo, "title");
	//draw_julia(mlx, win, -0.7, 0.27015, dimensiones);



	mlx_loop(fractal.mlx);
	return (0);
}

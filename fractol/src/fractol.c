#include "fractol.h"


void choose_fractal(t_fractal *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, f->name);
	create_img(f);
	init_fractal_values(f);

	if (ft_strncmp(f->name, "j", 2) == 0 || ft_strncmp(f->name, "Julia", 6) == 0)
	{
		f->cr = -0.7;
		f->ci = 0.27015;
	}
	if (ft_strncmp(f->name, "m", 2) == 0 || ft_strncmp(f->name, "Mandelbrot", 11) == 0)
	{
		f->cr = -0.8;
		f->ci = 0.0;
	}
	if (ft_strncmp(f->name, "s", 2) == 0)
	{
		//Using f->cr as DEPTH
		f->cr = 8;
	    draw_sierpinski(f);
		return ;
	}
	
	draw_fractal(f);
}


int main(int argc, char **argv)
{
	
	void	*mlx;
	t_fractal fractal;
	if (argc < 2){
		printf("Debes introducir un argumento\n");
		return (0);
	}
	
	init_fractal(&fractal);
	fractal.name = argv[1];
	choose_fractal(&fractal);

	mlx_hook(fractal.win, 2, 1L<<0, key_press, &fractal);
	mlx_hook(fractal.win, 3, 1L<<1, key_release, &fractal);
	mlx_mouse_hook(fractal.win, raton, &fractal);
	mlx_hook(fractal.win, 33, 1L<<0, close_window, &fractal);

	mlx_loop(fractal.mlx);
	return (0);
}

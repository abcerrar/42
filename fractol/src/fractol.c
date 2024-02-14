#include "fractol.h"

void choose_fractal(t_fractal *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, f->name);
	create_img(f);
	f->max_iter = MAX_ITER;
	if (ft_strncmp("Julia", f->name, 6) == 0 || ft_strncmp("j", f->name, 2) == 0)
	{
		init_fractal_values(f);
		draw_julia(f);
	}
	
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
	mlx_hook(fractal.win, 4, 1L<<2, raton, &fractal);
	mlx_hook(fractal.win, 6, 1L<<6, raton_movimiento, &fractal);
	mlx_mouse_hook(fractal.win, raton, &fractal);

	mlx_loop(fractal.mlx);
	return (0);
}

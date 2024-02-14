#include "fractol.h"


void	create_img(t_fractal *fractal){
	int bytes_per_pixel;
	int line_length;
	int endian;

	fractal -> img = mlx_new_image(fractal -> mlx, WIDTH, HEIGHT);
	//Blindarlo
	fractal -> addr = mlx_get_data_addr(fractal -> img, &bytes_per_pixel, &line_length, &endian);
	printf("%d\n", line_length);
	printf("%d\n", WIDTH);
}

void choose_fractal(t_fractal *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, f->name);
	create_img(f);
	f->max_iter = MAX_ITER;
	if (ft_strncmp("Julia", f->name, 6) == 0 || ft_strncmp("j", f->name, 2) == 0)
	{
		f->zoom = 2.5;
		f->cr = -0.7;
		f->ci = 0.27015;
		f->center_x = 0.0;
		f->center_y = 0.0;
		draw_julia(f);
	}
	
}

int tecla(int keycode, t_fractal *f)
{
	printf("keycode: %d\n", keycode);
	//	ZOOM
	if (keycode == PLUS)
		f->zoom = f->zoom - 0.1;
	if (keycode == MINUS)
		f->zoom = f->zoom + 0.1;
	//	MOVEMENT
	if (keycode == KEY_RIGTH)
		f->cr = f->cr + 0.01;
		//f->center_x -= 3.0;
	if (keycode == KEY_LEFT)
		f->cr = f->cr - 0.01;
		//f->center_x += 3.0;
	if (keycode == KEY_UP)
		f->center_y += 0.05;
	if (keycode == KEY_DOWN)
		f->center_y -= 0.05;
	//	EXIT
	if (keycode == ESC)
		mlx_destroy_window(f -> mlx, f -> win);
	//	RESET
	if (keycode == RESET)
	{
		f -> zoom = 2.5;
		f -> cr = -0.7;
		f -> ci = 0.27015;
		f->center_x = 0.0;
		f->center_y = 0.0;
	}
	draw_julia(f);
	return (0);
}

int raton(int button, int x, int y, t_fractal *f)
{
	//Calcular la coordenada compleja de la posicion del raton antes y despues del 
	//zoom y luego ajustar el centro a esas coordenadas.

	double	complex_x = f->center_x + (((double)x - WIDTH / 2) * (f->zoom / WIDTH));
	double	new_complex_x; 
	double	complex_y = f->center_y + (((double)y - HEIGHT / 2) * (f->zoom / HEIGHT));
	double	new_complex_y; 

	if (button == 4)
		f->zoom *= 0.9;
	if (button == 5)
		f->zoom /= 0.9;
	new_complex_x = f->center_x + (((double)x - WIDTH / 2) * (f->zoom / WIDTH));
	new_complex_y = f->center_y + (((double)y - HEIGHT / 2) * (f->zoom / HEIGHT));
	f->center_x += complex_x - new_complex_x;
	f->center_y -= complex_y - new_complex_y;
	draw_julia(f);
	return (0);
}



int raton_movimiento(int x, int y, t_fractal *fractal)
{
	return (0);
}


int main(int argc, char **argv)
{
	
	void	*mlx;
	t_fractal fractal;
	if (argc < 2){
		printf("Debes introducir un argumento\n");
		return (0);
	}
	
	fractal.name = argv[1];
	choose_fractal(&fractal);

	mlx_hook(fractal.win, 2, 1L<<0, tecla, &fractal);
	mlx_hook(fractal.win, 4, 1L<<2, raton, &fractal);
	mlx_hook(fractal.win, 6, 1L<<6, raton_movimiento, &fractal);
	mlx_mouse_hook(fractal.win, raton, &fractal);

	//mlx_loop_hook(fractal.mlx, next_frame, &fractal);
	mlx_loop(fractal.mlx);
	return (0);
}

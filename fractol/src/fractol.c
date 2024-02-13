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

void choose_fractal(t_fractal *fractal)
{
	fractal -> mlx = mlx_init();
	fractal -> win = mlx_new_window(fractal -> mlx, WIDTH, HEIGHT, fractal -> name);
	create_img(fractal);
	fractal -> max_iter = MAX_ITER;
	//Hacer el zoom infinito
	fractal -> zoom = 0.6;
	if (ft_strncmp("Julia", fractal -> name, 6) == 0 || ft_strncmp("j", fractal -> name, 2) == 0)
	{
		fractal -> cr = -0.7;
		fractal -> ci = 0.27015;
		fractal->center_x = WIDTH / 2;
		fractal->center_y = HEIGHT / 2;
		draw_julia(fractal);
	}
	
}

int tecla(int keycode, t_fractal *f)
{
	printf("keycode: %d\n", keycode);
	if (keycode == PLUS)
		f->zoom = f->zoom - 0.01;
	if (keycode == MINUS)
		f->zoom = f->zoom + 0.01;
	if (keycode == KEY_RIGTH)
		f->cr = f->cr + 0.01;
		//f->center_x -= 3.0;
	if (keycode == KEY_LEFT)
		f->cr = f->cr - 0.01;
		//f->center_x += 3.0;
	if (keycode == KEY_UP)
		f->center_y += 3.0;
	if (keycode == KEY_DOWN)
		f->center_y -= 3.0;
	if (keycode == ESC)
		mlx_destroy_window(f -> mlx, f -> win);
	draw_julia(f);
	return (0);
}

int raton(int button, int x, int y, t_fractal *fractal)
{
	if (button == 4)
		fractal -> zoom = fractal -> zoom - 0.01;
	if (button == 5)
		fractal -> zoom = fractal -> zoom + 0.01;

	if (button == 1)
		fractal -> pressed = 1;
	else
		fractal -> pressed = 0;
	//printf("Button: %d\n", button);
	//printf("x: %d\n", x);
	//printf("y: %d\n", y);
	draw_julia(fractal);

	return (0);
}



int raton_movimiento(int x, int y, t_fractal *fractal)
{
	if (fractal -> pressed == 1)
	{

	}
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

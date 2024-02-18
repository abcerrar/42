#ifndef FRACTOL_H

# define FRACTOL_H
# include "mlx.h"
# include "libft.h"
# include "keys.h"
# include <math.h>
# include <stdio.h>

typedef struct s_fractal
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;
	char	*name;
	int		x;
	int		y;
	int		max_iter;
	int		shift_pressed;
	int		color_position;
	double	center_x;
	double	center_y;
	double	zr;
	double	zi;
	double	cr;
	double	ci;
	double	zoom;
	double	zoom_factor;
	double	movement_speed;
}	t_fractal;

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 60


void	draw_fractal(t_fractal *fractal);

//Utils
void	my_mlx_pixel_put(t_fractal *f, int color);
void	init_fractal(t_fractal *f);
void	create_img(t_fractal *fractal);
void	init_fractal_values(t_fractal *f);
int		close_window(t_fractal *f);

//Events
int raton_movimiento(int x, int y, t_fractal *fractal);
int key_press(int keycode, t_fractal *f);
int raton(int button, int x, int y, t_fractal *f);
int key_release(int keycode, t_fractal *f);

//Color
int	get_color(t_fractal *f);

#endif

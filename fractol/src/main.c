#include "fractol.h"
#define MAX_ITER 100

void draw_julia(void *mlx, void *img, double cr, double ci, int dimensions[]);

typedef struct s_data{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_data;

/*
int julia_escape_time(double cr, double ci, double zr, double zi) {
    int n = 0;
    while (zr*zr + zi*zi <= 4 && n < MAX_ITER) {
        double tmp = zr*zr - zi*zi + cr;
        zi = 2*zr*zi + ci;
        zr = tmp;
        n++;
    }
    return n;
}

void draw_julia_set(void *mlx, void *win, double cr, double ci) {
    for (int x = 0; x < 800; x++) {
        for (int y = 0; y < 600; y++) {
            // Mapeo de coordenadas de píxeles a números complejos
            double zr = (x - 400) / 200.0;
            double zi = (y - 300) / 200.0;
            int n = julia_escape_time(cr, ci, zr, zi);
            int color = (n == MAX_ITER) ? 0 : 0xFFFFFF * n / MAX_ITER;
            mlx_pixel_put(mlx, win, x, y, color);
        }
    }
}
*/
/*
void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
*/

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int ancho = 800;
	int largo = 800;

	mlx = mlx_init();
	//mlx_win = mlx_new_window(mlx, ancho, largo, "test1");
	//img.img = mlx_new_image(mlx, ancho, largo);
	//img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	//my_mlx_pixel_put(&img, j, i, 0x00FF0000);

	//Ej julia
	/*
	void *win = mlx_new_window(mlx, 800, 600, "Conjunto de Julia");
    //Ejemplo de c = -0.7 + 0.27015i
    draw_julia_set(mlx, win, ft_atoi(argv[1]), 0.27015);
	*/

	void *win = mlx_new_window(mlx, ancho, largo, "title");
	int dimensiones[] = {ancho, largo};
	draw_julia(mlx, win, -0.7, 0.27015, dimensiones);



	mlx_loop(mlx);
}

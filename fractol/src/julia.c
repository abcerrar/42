#include "fractol.h"

void map_to_complex(void *mlx, void *win, int dimensions[], double c[], int max_iter)
{
	int px = 0;
	int py = 0;

	printf("Dimensions: %d, %d\n", dimensions[0], dimensions[1]);

	while (px++ < dimensions[0]){
		while (py++ < dimensions[1])
			mlx_pixel_put(mlx, win, px, py, 0x0000FF00);
		py = 0;
	}
}

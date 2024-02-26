#include "fractol.h"

/*void	fill_triangle(t_fractal *f, t_point a, t_point b, t_point c)
{
	int side_length = sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
    float height = side_length * sqrt(3) / 2;
    
    // Bucle para recorrer cada píxel dentro del triángulo
    for (int y = a.y; y <= b.y; y++) {
        // Calcula la posición de inicio y fin de la línea horizontal en función de la altura
        int start_x = a.x - (y - a.y) / sqrt(3);
        int end_x = a.x + (y - a.y) / sqrt(3);
        
        // Colorea los píxeles en la línea horizontal
		draw_line(f->mlx, f->win, (t_point){start_x, y}, (t_point){end_x, y}, get_color(f) * 50);
    }
}*/

void print_point(t_point punto, char *nombre)
{
	printf("Punto %s: [x: %d, y: %d]\n", nombre, punto.x, punto.y);
}

void fill_triangle2(t_fractal f, t_point a, t_point b, t_point c)
{
	t_point top;
	t_point left;
	t_point rigth;
	if (a.y < b.y && a.y < c.y)
		top = a;
	else if (b.y < c.y)
		top = b;
	else
		top = c;
	if (a.x < b.x && a.x < c.x)
		rigth = a;
	else if (b.x < c.x)
		rigth = b;
	else
		rigth = c;
	if (a.x > b.x && a.x > c.x)
		left = a;
	else if (b.x > c.x)
		left = b;
	else
		left = c;

	while (rigth.x++ < left.x)
		draw_line(f.mlx, f.win, top, rigth, get_color(&f) * 50);

}

void draw_triangle(t_fractal *f, t_point a, t_point b, t_point c) {
	draw_line(f->mlx, f->win, a, b, get_color(f) * 50);
	draw_line(f->mlx, f->win, b, c, get_color(f) * 50);
	draw_line(f->mlx, f->win, c, a, get_color(f) * 50);
	fill_triangle2(*f, a, b, c);
}

void draw_sierpinski(t_fractal *f, t_point a, t_point b, t_point c, int depth)
{
    t_point mid_ab, mid_bc, mid_ca;
	
	if (f->cr < 0)
		f->cr = 0;
	if (depth <= 0)
		draw_triangle(f, a, b, c);
	else
	{
        mid_ab.x = (a.x + b.x) / 2;
        mid_ab.y = (a.y + b.y) / 2;
        mid_bc.x = (b.x + c.x) / 2;
        mid_bc.y = (b.y + c.y) / 2;
        mid_ca.x = (c.x + a.x) / 2;
        mid_ca.y = (c.y + a.y) / 2;
		draw_sierpinski(f, a, mid_ab, mid_ca, depth - 1);
		draw_sierpinski(f, mid_bc, b, mid_ab, depth - 1);
		draw_sierpinski(f, mid_bc, mid_ca, c, depth - 1);
	}

}

/*
void draw_sierpinski(void *mlx_ptr, void *win_ptr, int depth) {
    Point points[3] = {{100, 500}, {700, 500}, {400, 100}}; // Puntos del triángulo inicial

    // Dibuja el triángulo inicial
    draw_triangle(mlx_ptr, win_ptr, points[0], points[1], points[2]);

    // Iterativamente calcula y dibuja los triángulos más pequeños
    for (int i = 0; i < depth; i++) {
        Point mid_ab = {(points[0].x + points[1].x) / 2, (points[0].y + points[1].y) / 2};
        Point mid_bc = {(points[1].x + points[2].x) / 2, (points[1].y + points[2].y) / 2};
        Point mid_ca = {(points[2].x + points[0].x) / 2, (points[2].y + points[0].y) / 2};

        // Dibuja los triángulos más pequeños
        draw_triangle(mlx_ptr, win_ptr, points[0], mid_ab, mid_ca);
        draw_triangle(mlx_ptr, win_ptr, mid_ab, points[1], mid_bc);
        draw_triangle(mlx_ptr, win_ptr, mid_ca, mid_bc, points[2]);

        // Actualiza los puntos para la próxima iteración
        points[0] = mid_ab;
        points[1] = mid_bc;
        points[2] = mid_ca;
    }
}
*/

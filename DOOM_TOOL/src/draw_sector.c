#include "../inc/doom.h"
#include <stdint.h>
#include <stdio.h>
int	draw_wall(t_main main, t_wall *wall, uint32_t color)
{
	t_point point_a = *wall->point_a;
	t_point	point_b = *wall->point_b;

	point_a.x *= (main.zoom);
	point_a.x += main.gap_width;
	point_a.y *= (main.zoom);
	point_a.y += main.gap_hight;
	point_b.x *= (main.zoom);
	point_b.x += main.gap_width;
	point_b.y *= (main.zoom);
	point_b.y += main.gap_hight;
	//printf("\n\e[1A\e[2KPoint B| X: %f,Y: %f\n", point_b.x, point_b.y);
	dda_trace_line(main.mlx_data, point_a, point_b, color);
	return (0);
}

int	draw_neighbor(t_main main, t_wall **neighbor, uint32_t color)
{
	for(int i = 0; neighbor[i]; i++)
		draw_wall(main, neighbor[i], color);
	return (0);
}

//int	draw_point()

int	draw_sector(t_main main, t_point **point_array, uint32_t color)
{
	for(int i = 0; point_array[i]; i++)
	{
		//draw_point(mlx_data.mlx, point_array[i]->x, point_array[i]->y);
		mouv_point(&main, point_array[i]);
		draw_neighbor(main, point_array[i]->neighbor, color);
	}
	return (0);
}

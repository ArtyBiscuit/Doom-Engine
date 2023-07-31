#include "../inc/doom.h"

void	dda_trace_line(t_mlx_data mlx_data, t_point start_point, t_point end_point, uint32_t color)
{
	float	d_y;
	float	d_x;
	float	steps;
	float	cmp;

	d_y = end_point.y - start_point.y;
	d_x = end_point.x - start_point.x;
	steps = (float)fmax(fabs(d_x), fabs(d_y));
	d_x = d_x / steps;
	d_y = d_y / steps;
	cmp = 0.0f;
	while (++cmp <= steps)
	{
		if (start_point.x < mlx_data.mlx->width && start_point.y < mlx_data.img->height)
			mlx_put_pixel(mlx_data.img, start_point.x, start_point.y, color);
		start_point.x += d_x;
		start_point.y += d_y;
	}
}

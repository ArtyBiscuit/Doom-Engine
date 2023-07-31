#include "../inc/doom.h"

void	display_grid(t_main main, uint32_t color)
{
	for (int i = 0; i < main.mlx_data.mlx->height; i++)
	{
		for (int j = 0; j < main.mlx_data.mlx->width; j++)
		{
			if (!((i - main.gap_hight) % main.zoom) || !((j - main.gap_width) % main.zoom))
				mlx_put_pixel(main.mlx_data.img, j, i, color);
		}
	}

}

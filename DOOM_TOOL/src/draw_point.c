#include "../inc/doom.h"

void    draw_point(t_main *main, unsigned int color)
{
    int point_size = 5;
    int dist = 0;
    int cur_x;
    int cur_y;

    for (int cur_point = 0; cur_point < 6; cur_point++)
    {
        for (int i = 0; i < point_size * 2; i++)
        {
            for (int j = 0; j < point_size * 2; j++)
            {
                dist = sqrt((i - point_size) * (i - point_size) + (j - point_size) * (j - point_size));
                cur_x = i + main->point_array[cur_point]->x * main->zoom - point_size;
                cur_x += main->gap_width;
                cur_y = j + main->point_array[cur_point]->y * main->zoom - point_size;
                cur_y += main->gap_hight;
                if (dist < point_size)
                {
                    if (cur_x < WIDTH && cur_x > 0 && cur_y < HEIGHT && cur_y > 0)
                    {
                        if (!check_over_point(main, main->point_array[cur_point]))
                            mlx_put_pixel(main->mlx_data.img, cur_x, cur_y, color);
                        else
                            mlx_put_pixel(main->mlx_data.img, cur_x, cur_y, 0x0251bfff);

                    }
                }
            }
        }
    }
}
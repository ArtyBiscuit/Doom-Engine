#include "../inc/doom.h"

int check_over_point(t_main *main, t_point *point)
{


    int dist;
    int point_size = 5;

    int mouse_x;
    int mouse_y;

    int cur_x;
    int cur_y;

    mlx_get_mouse_pos(main->mlx_data.mlx, &mouse_x, &mouse_y);
    for (int i = 0; i < point_size * 2; i++)
    {
        for (int j = 0; j < point_size * 2; j++)
        {
            dist = sqrt((i - point_size) * (i - point_size) + (j - point_size) * (j - point_size));
            cur_x = i + point->x * main->zoom - point_size;
            cur_x += main->gap_width;
            cur_y = j + point->y * main->zoom - point_size;
            cur_y += main->gap_hight;
            if (dist < point_size)
            {
                if (cur_x == mouse_x && cur_y == mouse_y)
                    return (1);
            }
        }
    }
    return (0);
}
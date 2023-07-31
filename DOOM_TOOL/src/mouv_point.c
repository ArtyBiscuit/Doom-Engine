#include "../inc/doom.h"

int mouv_point(t_main *main, t_point *point)
{
    int x = 0;
    int y = 0;
    if (check_over_point(main, point) && mlx_is_mouse_down(main->mlx_data.mlx, MLX_MOUSE_BUTTON_LEFT))
        point->select = true;
    else if (!mlx_is_mouse_down(main->mlx_data.mlx, MLX_MOUSE_BUTTON_LEFT))
        point->select = false;
    if (point->select)
    {
        mlx_get_mouse_pos(main->mlx_data.mlx, &x, &y);
        x -= (point->x * main->zoom) + main->gap_width;
        y -= (point->y * main->zoom) + main->gap_hight;
        point->x += (float)x / 10;
        point->y += (float)y / 10;
        mlx_set_mouse_pos(main->mlx_data.mlx, (point->x * main->zoom) + main->gap_width, (point->y * main->zoom) + main->gap_hight);
    }
    return (0);
}
#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include "../lib/minilibx/include/MLX42/MLX42.h"

#define PI 3.14159265359
#define MLX_ERROR 1
#define WIDTH 1080
#define HEIGHT 720

/***************  STRUCT  ****************/

typedef struct s_mlx_data	t_mlx_data;
typedef struct s_point		t_point;
typedef struct	s_wall		t_wall;
typedef struct	s_main		t_main;
typedef struct	s_mouse		t_mouse;

struct s_mlx_data
{
	mlx_t		*mlx;
	mlx_image_t	*img;
};

struct s_mouse
{
	int pos_x;
	int pos_y;
};


struct	s_main
{
	t_mlx_data	mlx_data;
	int			zoom;
	int			gap_hight;
	int			gap_width;
	t_wall		*wall_array;
	t_point		**point_array;
	int x;
	int y;
	int			number_of_point;
	int			number_of_wall;
};

struct	s_wall
{
//	uint32_t	color;
	t_point		*point_a;
	t_point		*point_b;
};

struct	s_point
{
	int		id;
	float	x;
	float	y;
	t_wall	**neighbor;
	bool	select;
};
/*****************************************/

void	display_grid(t_main main, uint32_t color);
void	dda_trace_line(t_mlx_data mlx_data, t_point start_point, t_point end_point, uint32_t color);
int		draw_sector(t_main main, t_point **point_array, uint32_t color);
void    draw_point(t_main *main, unsigned int color);
t_point	*new_point(float x, float y);
t_wall	*new_wall(t_point *point_a, t_point *point_b);

int check_over_point(t_main *main, t_point *point);
int mouv_point(t_main *main, t_point *point);



#endif

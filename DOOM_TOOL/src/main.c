#include "../inc/doom.h"
#include <stdbool.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>


void my_keyhook(mlx_key_data_t keydata, void* param)
{
	t_main *main = (t_main *)param;
	// If we PRESS the 'J' key, print "Hello".
	if (keydata.key == 265 && keydata.action == MLX_REPEAT)
		main->gap_hight+=15;
	if (keydata.key == 264 && keydata.action == MLX_REPEAT)
		main->gap_hight-=15;
	if (keydata.key == 262 && keydata.action == MLX_REPEAT)
		main->gap_width+=15;
	if (keydata.key == 263 && keydata.action == MLX_REPEAT)
		main->gap_width-=15;
	if (keydata.key == 61 && keydata.action == MLX_REPEAT)
		main->zoom*=1.1;
	if (keydata.key == 45 && keydata.action == MLX_REPEAT)
		main->zoom/=1.1;
}

// Exit the program as failure.
static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// Print the window width and height.
static void ft_hook(void* param)
{
	t_main *main = (t_main *)param;
	if (main->zoom == 3)
		main->zoom = 4;
	memset(main->mlx_data.img->pixels, 0, main->mlx_data.img->width * main->mlx_data.img->height * sizeof(int32_t));
	//mouse(main);
	display_grid(*main, 0x6e6e6eFF);
	//draw_sector(mlx_data, p1, 0xFFFFFFFF);
	draw_sector(*main, main->point_array, 0x0f0f0fff);
	draw_point(main, 0x000e24ff);
//	mlx_image_to_window(main->mlx_data.mlx, main->mlx_data.img, 0, 0);
	return ;
}

int32_t	main(void)
{
	t_main		main;
	main.zoom=10;

	// MLX allows you to define its core behaviour before startup.
	//mlx_set_setting(MLX_MAXIMIZED, true);
	main.mlx_data.mlx = mlx_init(WIDTH, HEIGHT, "Doom_map_tool", true);
	if (!main.mlx_data.mlx)
		ft_error();

	/* Do stuff *
	 */
	// Create and display the image.
	main.mlx_data.img = mlx_new_image(main.mlx_data.mlx, WIDTH, HEIGHT);
	if (!main.mlx_data.img || (mlx_image_to_window(main.mlx_data.mlx, main.mlx_data.img, 0, 0) < 0))
		ft_error();

	main.gap_width =  main.mlx_data.mlx->width / 2;
	main.gap_hight =  main.mlx_data.mlx->height / 2;
	main.point_array = malloc(sizeof(t_point *) * 7);

	main.point_array[0]=new_point(20, 20);
	main.point_array[0]->id = 1;
	main.point_array[1]=new_point(50, 20);
	main.point_array[2]=new_point(50, 50);
	main.point_array[3]=new_point(40, 60);
	main.point_array[4]=new_point(30, 60);
	main.point_array[5]=new_point(20, 50);
	main.point_array[6]=NULL;

	new_wall(main.point_array[0], main.point_array[1]);
	new_wall(main.point_array[1], main.point_array[2]);
	new_wall(main.point_array[2], main.point_array[3]);
	new_wall(main.point_array[3], main.point_array[4]);
	new_wall(main.point_array[4], main.point_array[5]);
	new_wall(main.point_array[5], main.point_array[0]);





	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	mlx_key_hook(main.mlx_data.mlx, my_keyhook, &main);
	mlx_loop_hook(main.mlx_data.mlx, ft_hook, &main);
	mlx_loop(main.mlx_data.mlx);
	mlx_terminate(main.mlx_data.mlx);
	//free(mlx);
	//free(img);
	return (EXIT_SUCCESS);
}

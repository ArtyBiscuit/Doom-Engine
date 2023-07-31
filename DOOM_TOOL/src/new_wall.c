#include "../inc/doom.h"
#include <stdlib.h>

int	get_neighbor_nember(t_wall **neighbor)
{
	int	number_of_neighnor;

	if (!neighbor)
		return (0);
	number_of_neighnor = 0;
	while(neighbor[number_of_neighnor])
		number_of_neighnor++;
	return (number_of_neighnor);
}

t_wall	**add_wall_neighbor(t_wall *wall, t_wall **neighbor)
{
	int		i;
	int		curent_neighbor_size;
	t_wall	**new_neighbor;

	curent_neighbor_size = get_neighbor_nember(neighbor);
	new_neighbor = malloc(sizeof(t_wall *) * (curent_neighbor_size + 2));
	if (!wall || !new_neighbor)
		return (NULL);
	for(i = 0; i < curent_neighbor_size; i++)
		new_neighbor[i] = neighbor[i]; 
	new_neighbor[i] = wall;
	new_neighbor[i + 1] = NULL;
	if (neighbor)
		free(neighbor);
	return (new_neighbor);
}

t_wall	*new_wall(t_point *point_a, t_point *point_b)
{
	t_wall	**neighbor_a;
	t_wall	**neighbor_b;
	t_wall	*new_wall;

	new_wall = malloc(sizeof(t_wall) * 1);
	if (!new_wall)
		return (NULL);
	new_wall->point_a = point_a;
	new_wall->point_b = point_b;
	neighbor_a = new_wall->point_a->neighbor;
	neighbor_b = new_wall->point_b->neighbor;
	neighbor_a = add_wall_neighbor(new_wall, neighbor_a);
	neighbor_b = add_wall_neighbor(new_wall, neighbor_b);
	new_wall->point_a->neighbor = neighbor_a;
	new_wall->point_b->neighbor = neighbor_b;
	return (new_wall);
}

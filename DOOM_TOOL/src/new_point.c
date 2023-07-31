#include "../inc/doom.h"
#include <stdlib.h>

t_point	*new_point(float x, float y)
{
	t_point *new_point;

	new_point = malloc(sizeof(t_point) * 1);
	if (!new_point)
		return (NULL);
	new_point->x = x;
	new_point->y = y;
	new_point->neighbor = NULL;
	new_point->select = false;
	return (new_point);
}

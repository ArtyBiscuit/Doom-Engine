#include "../inc/doom.h"

int	sector_detection(t_point *sector_start_point)
{
	t_point	*start_point;
	t_point	*curent_point;

	start_point = sector_start_point;
	if (!start_point)
		return (1);
	curent_point = start_point;
	if (!start_point->a)
		return (1);
	else
	{
		while(curent_point)
		{
			curent_point = curent_point->a;
			if (curent_point == start_point)
				return (0);
		}
	}
	return (1);
}

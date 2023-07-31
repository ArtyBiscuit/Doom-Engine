/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:02:47 by arforgea          #+#    #+#             */
/*   Updated: 2023/05/25 17:14:18 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/doom.h"

void	dda(t_point start, t_point end, t_mlx_img *img)
{
	float	d_y;
	float	d_x;
	float	steps;
	float	cmp;

	d_y = end.y - start.y;
	d_x = end.x - start.x;
	steps = (float)fmax(fabs(d_x), fabs(d_y));
	d_x = d_x / steps;
	d_y = d_y / steps;
	cmp = 0.0f;
	while (++cmp <= steps)
	{
		//pixel_put(img, start.x, start.y, start.color);
		start.x += d_x;
		start.y += d_y;
	}
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevilla <rlevilla42@student.42lausanne.c  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 22:46:07 by rlevilla          #+#    #+#             */
/*   Updated: 2023/05/14 23:11:37 by rlevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
void	bresenham(t_map *map, float x1, float y1, float x2, float y2)
{
	int	z1;
	int	z2;

	z1 = map->z[(int)y1][(int)x1];
	z2 = map->z[(int)y2][(int)x2];
	if (z1 != 0 || z2 != 0)
		map->color = PINK;
	else
		map->color = WHITE;
	isometric(&x1, &y1, z1);
	isometric(&x2, &y2, z2);
	x1 *= map->zoom;
	y1 *= map->zoom;
	x2 *= map->zoom;
	y2 *= map->zoom;
	map->ex = fabs(x2 - x1);
	map->ey = fabs(y2 - y1);
	map->dx = 2 * map->ex;
	map->dy = 2 * map->ey;
	map->Dx = map->ex;
	map->Dy = map->ey;
	set_shift(&x1, &y1, &x2, &y2);
	if (map->Dx > map->Dy)
		dx_sup_dy(map, x1, y1, x2, y2);
	else
		dx_inf_dy(map, x1, y1, x2, y2);
}*/

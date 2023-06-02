/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevilla <rlevilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:52:54 by rlevilla          #+#    #+#             */
/*   Updated: 2023/05/25 01:10:31 by rlevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	dx_sup_dy(t_map *map, t_point point)
{
	int	x_incr;
	int	y_incr;
	int	i;

	i = 0;
	x_incr = 1;
	y_incr = 1;
	if (map->x1 > map->x2)
		x_incr = -1;
	if (map->y1 > map->y2)
		y_incr = -1;
	while (i <= point.ddx)
	{
		if (map->x1 < 1920 && map->y1 < 1080 && map->x1 >= 0 && map->y1 >= 0)
			my_mlx_pixel_put(map, map->x1, map->y1, map->color);
		i++;
		map->x1 += x_incr;
		point.ex -= point.dy;
		if (point.ex < 0)
		{
			map->y1 += y_incr;
			point.ex += point.dx;
		}
	}
}

void	dx_inf_dy(t_map *map, t_point point)
{	
	int	x_incr;
	int	y_incr;
	int	i;

	i = 0;
	x_incr = 1;
	y_incr = 1;
	if (map->x1 > map->x2)
		x_incr = -1;
	if (map->y1 > map->y2)
		y_incr = -1;
	while (i <= point.ddy)
	{
		if (map->x1 < 1920 && map->y1 < 1080 && map->x1 >= 0 && map->y1 >= 0)
			my_mlx_pixel_put(map, map->x1, map->y1, map->color);
		i++;
		map->y1 += y_incr;
		point.ey -= point.dx;
		if (point.ey < 0)
		{
			map->x1 += x_incr;
			point.ey += point.dy;
		}
	}
}

void	bresenham(t_map *map)
{
	t_point	point;
	int		z1;
	int		z2;

	z1 = map->z[(int)map->y1][(int)map->x1];
	z2 = map->z[(int)map->y2][(int)map->x2];
	if (z1 != 0 || z2 != 0)
		map->color = PINK;
	else
		map->color = WHITE;
	isometric(&map->x1, &map->y1, z1);
	isometric(&map->x2, &map->y2, z2);
	apply_zoom(map);
	point.ex = fabs(map->x2 - map->x1);
	point.ey = fabs(map->y2 - map->y1);
	point.dx = 2 * point.ex;
	point.dy = 2 * point.ey;
	point.ddx = point.ex;
	point.ddy = point.ey;
	set_shift(map);
	if (point.ddx > point.ddy)
		dx_sup_dy(map, point);
	else
		dx_inf_dy(map, point);
}

void	draw_file(t_map *map, t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
			{
				set_point_line(map, x, y);
				bresenham(map);
			}
			if (y < data->height - 1)
			{
				set_point_column(map, x, y);
				bresenham(map);
			}
			x++;
		}
		y++;
	}
}

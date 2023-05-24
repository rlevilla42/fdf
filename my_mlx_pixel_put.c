/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevilla <rlevilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:48:41 by rlevilla          #+#    #+#             */
/*   Updated: 2023/05/25 01:21:46 by rlevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_map *map, int x, int y, int color)
{
	char	*dst;

	dst = map->img_addr + (y * map->line_length
			+ x *(map->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	isometric(float *x, float *y, int z)
{
	double	angle_1;
	double	angle_2;

	angle_1 = 0.8;
	angle_2 = 0.8;
	*x = (*x - *y) * cos(angle_1);
	*y = (*x + *y) * sin(angle_2) + z * (-1);
}
/*
void	set_zoom(t_map *map, t_data *data)
{
	float	zoom1;
	float	zoom2;

	if (data->width > 0 && data->width < 99)
		zoom1 = 10.0;
	else if (data->width >= 100 && data->width < 500)
		zoom1 = 2.0;
	else
		zoom1 = 1.0;
	if (data->height > 0 && data->height < 99)
		zoom2 = 10.0;
	else if (data->height >= 100 && data->height < 500)
		zoom2 = 2.0;
	else
		zoom2 = 1.0;
	if (zoom1 > zoom2)
		map->zoom = zoom2;
	else
		map->zoom = zoom1;
}

void	set_shift(float *x1, float *y1, float *x2, float *y2)
{
	*x1 *= 960; // shift x = size screen x (1920) / 2
	*y1 *= 460; // shift y = size screen y (1080) / 2
	*x2 *= 960;
	*y2 *= 460;
}

void	isometric(float *x, float *y, int z)
{
	float	a;
	float	b;

	a = 0.43;
	b = 2;
	*x = *x * cos(a) + *y * cos(a + b) + z * cos(a - b);
	*y = *x * sin(a) + *y * sin(a + b) + z * sin(a - b);
}*/

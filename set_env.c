/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevilla <rlevilla42@student.42lausanne.c  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 21:42:36 by rlevilla          #+#    #+#             */
/*   Updated: 2023/05/25 01:26:43 by rlevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

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

void	set_shift(t_map *map)
{
	map->x1 += 960;
	map->y1 += 490;
	map->x2 += 960;
	map->y2 += 490;
}

void	apply_zoom(t_map *map)
{
	map->x1 *= map->zoom;
	map->y1 *= map->zoom;
	map->x2 *= map->zoom;
	map->y2 *= map->zoom;
}

void	set_point_line(t_map *map, int x, int y)
{
	map->x1 = x;
	map->y1 = y;
	map->x2 = x + 1;
	map->y2 = y;
}

void	set_point_column(t_map *map, int x, int y)
{
	map->x1 = x;
	map->y1 = y;
	map->x2 = x;
	map->y2 = y + 1;
}

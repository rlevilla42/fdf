/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevilla <rlevilla42@student.42lausanne.c  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 00:26:39 by rlevilla          #+#    #+#             */
/*   Updated: 2023/05/25 01:12:12 by rlevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
void	init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx_ptr, 1920, 1080, "fdf");
	data->img = mlx_new_image(data->mlx_ptr, 1920, 1080);
	data->img_addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	my_mlx_pixel_put(data, 5, 5, 0x00FF1493);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img_addr, 0, 0);
	mlx_loop(data->mlx_ptr);
}
*/
void	init(t_data *data, t_map *map)
{
	data->mlx_ptr = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx_ptr, 1920, 1080, "fdf");
	data->img = mlx_new_image(data->mlx_ptr, 1920, 1080);
	map->img_addr = mlx_get_data_addr(data->img, &map->bits_per_pixel,
			&map->line_length, &map->endian);
}

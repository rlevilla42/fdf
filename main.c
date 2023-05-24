/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevilla <rlevilla@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:06:20 by rlevilla          #+#    #+#             */
/*   Updated: 2023/05/25 01:37:58 by rlevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
int	deal_key(int key, void *data)
{
	(void)data;
	ft_printf("%d", key);
	return (0);
}
*/

int	check_input(int argc)
{
	if (argc != 2)
	{
		ft_printf("argument error\n");
		exit(0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_map	*map;

	check_input(argc);
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		exit(0);
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
	{
		free(data);
		exit(0);
	}
	init(data, map);
	parsing(map, data, argv);
	set_zoom(map, data);
	draw_file(map, data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->img, 0, 0);
	mlx_hook(data->mlx_win, 17, 0, close_win, data);
	mlx_hook(data->mlx_win, 2, 0, key_hook, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevilla <rlevilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:59:53 by rlevilla          #+#    #+#             */
/*   Updated: 2023/05/25 00:38:37 by rlevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# define PINK 0xFF1493
# define WHITE 0xFFFFFF

typedef struct s_data
{
	void	*img;
	void	*mlx_ptr;
	void	*mlx_win;
	int		x;
	int		y;
	int		height;
	int		width;
	void	*ptr_map;
}	t_data;

typedef struct bresenham
{
	char	*img_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		zoom;
	int		shift;
	int		color;
	int		**z;
	float	x;
	float	y;
	float	x1;
	float	y1;
	float	x2;
	float	y2;
	float	dx;
	float	dy;
	float	ddx;
	float	ddy;
	float	ex;
	float	ey;
}	t_map;

typedef struct points
{
	float	x;
	float	y;
	float	x1;
	float	y1;
	float	x2;
	float	y2;
	float	dx;
	float	dy;
	float	ddx;
	float	ddy;
	float	ex;
	float	ey;
}	t_point;

void	parsing(t_map *map, t_data *data, char **argv);
int		get_width(char **argv);
void	init(t_data *data, t_map *map);
void	my_mlx_pixel_put(t_map *map, int x, int y, int color);
void	bresenham(t_map *map);
void	draw_file(t_map *map, t_data *data);
void	isometric(float *x, float *y, int z);
void	set_zoom(t_map *map, t_data *data);
void	set_shift(t_map *map);
void	dx_sup_dy(t_map *map, t_point point);
void	dx_inf_dy(t_map *map, t_point point);
void	apply_zoom(t_map *map);
void	set_point_line(t_map *map, int x, int y);
void	set_point_column(t_map *map, int x, int y);
int		close_win(int key, t_data *data);
int		key_hook(int key, t_data *data);
void	free_array_int(t_data *data, t_map *map);
void	free_split(char **temp);

#endif

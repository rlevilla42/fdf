/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevilla <rlevilla42@student.42lausanne.c  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 23:21:59 by rlevilla          #+#    #+#             */
/*   Updated: 2023/05/25 00:38:56 by rlevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_win(int key, t_data *data)
{
	if (key == 53)
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	exit(0);
}

int	key_hook(int key, t_data *data)
{
	if (key == 53)
		close_win(key, data);
	exit(0);
}

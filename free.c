/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevilla <rlevilla42@student.42lausanne.c  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 00:26:39 by rlevilla          #+#    #+#             */
/*   Updated: 2023/05/25 01:12:12 by rlevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_array_int(t_data *data, t_map *map)
{
	int	j;

	j = 0;
	while (j < data->height)
	{
		free(map->z[j]);
		j++;
	}
	free(map->z);
}

void	free_split(char **temp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (temp[j + 1] != NULL)
	{
		free(temp[j]);
		j++;
	}
	free(temp[j]);
	free(temp);
}

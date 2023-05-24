/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevilla <rlevilla@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:34:19 by rlevilla          #+#    #+#             */
/*   Updated: 2023/05/25 01:25:21 by rlevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
int	ft_count_word(char *s, char c)
{
	int	i;
	int	word;
	
	i = 0;
	word = 0;
	while (s[i] == c && s[i])
		i++;
	if (!s[i])
		return (word);
	while (s[i])
	{
		if (s[i] == c)
		{
			word++;
			while (s[i] && s[i] == c)
				i++;
		}
		else
			i++;
	}
	return (word + 1);
}
*/
void	free_array(char **temp)
{
	int	j;

	j = 0;
	while (temp[j] != NULL)
	{
		free(temp[j]);
		j++;
	}
	free(temp);
}

int	get_height(char **argv)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		i++;
		line = get_next_line(fd);
	}
	close(fd);
	return (i);
}
/*
void	aff_split(char **str)
{
	int	j = 0;
	while (str[j] != NULL)
	{
		printf("str[%d] = %s\n", j, str[j]);
		j++;
	}
	return ;
}
*/

int	get_width(char **argv)
{
	int		i;
	int		fd;
	char	*line;
	char	**temp;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	temp = ft_split(line, ' ');
	while (temp[i] != NULL)
		i++;
	close(fd);
	return (i);
}

void	parsing_line(t_map *map, t_data *data, int j, char *line)
{
	int		i;
	char	**temp;

	i = 0;
	temp = ft_split(line, ' ');
	map->z[j] = (int *)malloc(sizeof(int) * data->width);
	if (!map->z[j])
		return ;
	while (i < data->width)
	{
		map->z[j][i] = ft_atoi(temp[i]);
		i++;
	}
	free_array(temp);
}

void	parsing(t_map *map, t_data *data, char **argv)
{
	int		j;
	int		fd;
	char	*line;

	j = 0;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	data->height = get_height(argv);
	data->width = get_width(argv);
	map->z = (int **)malloc(sizeof(int *) * data->height);
	if (!map->z)
		return ;
	while (j < data->height)
	{
		parsing_line(map, data, j, line);
		j++;
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

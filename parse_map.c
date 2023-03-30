/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engirald <engirald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:10:35 by engirald          #+#    #+#             */
/*   Updated: 2023/03/30 20:24:25 by engirald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include <fcntl.h>

static int	check_extension(char *file_path)
{
	char *ext = ft_strrchr(file_path, '.');
     
    if (ext == NULL || ft_strcmp(ext, ".ber") != 0)
		return (0);
	return (1);
}

static int	check_matrix(char **matrix, int height, int width)
{
	int i;
	int j;

	i = 0;
	while (i < height)
	{
		if ((int)ft_strlen(matrix[i]) != width)
			return (0);
		j = 0;
		while (j < width)
		{
			if (!ft_strchr(VALID_CHARS, matrix[i][j]))
				return (0);
			if ((i == 0 || i == height - 1 || j == 0 || j == width - 1) && matrix[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int parse_map(char *file_path, t_map *map)
{
	int		fd;
	char	*line;
	int		i;

	if (!check_extension(file_path))
		return (0);
	if ((fd = open(file_path, O_RDONLY)) < 0)
		return (0);
	map->width = -1;
	map->height = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (map->width == -1)
			map->width = ft_strlen(line);
		if (check_extension(line) || !check_matrix(&line, 1, map->width))
		{
			free(line);
			close(fd);
			return (0);
		}
		map->height++;
		free(line);
	}
	if (!check_matrix(map->matrix, map->height, map->width))
		return (0);
	close(fd);
	return (1);

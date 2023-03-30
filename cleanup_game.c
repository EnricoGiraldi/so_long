/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engirald <engirald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:42:16 by engirald          #+#    #+#             */
/*   Updated: 2023/03/30 20:42:27 by engirald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	cleanup_game(t_map *map)
{
	int i;

	mlx_destroy_image(map->mlx, map->img);
	mlx_destroy_window(map->mlx, map->win);
	i = 0;
	while (i < map->height)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
	i = 0;
	while (i < map->num_collectibles)
	{
		free(map->collectibles[i]);
		i++;
	}
	free(map->collectibles);
	free(map);
	exit(EXIT_SUCCESS);
}

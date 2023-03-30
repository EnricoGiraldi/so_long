/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engirald <engirald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:38:38 by engirald          #+#    #+#             */
/*   Updated: 2023/03/30 20:38:59 by engirald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	draw_game(t_map *map)
{
	int		x;
	int		y;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (map->grid[y][x] == '1')
				mlx_put_image_to_window(mlx_ptr, win_ptr, wall_img, x * TILE_SIZE, y * TILE_SIZE);
			else if (map->grid[y][x] == '0')
				mlx_put_image_to_window(mlx_ptr, win_ptr, floor_img, x * TILE_SIZE, y * TILE_SIZE);
			else if (map->grid[y][x] == 'C')
				mlx_put_image_to_window(mlx_ptr, win_ptr, collectible_img, x * TILE_SIZE, y * TILE_SIZE);
			else if (map->grid[y][x] == 'E')
				mlx_put_image_to_window(mlx_ptr, win_ptr, exit_img, x * TILE_SIZE, y * TILE_SIZE);
			else if (map->grid[y][x] == 'P')
				mlx_put_image_to_window(mlx_ptr, win_ptr, player_img, x * TILE_SIZE, y * TILE_SIZE);
		}
	}
}

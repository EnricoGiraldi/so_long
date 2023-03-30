/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engirald <engirald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:36:25 by engirald          #+#    #+#             */
/*   Updated: 2023/03/30 20:37:58 by engirald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	init_game(t_map *map)
{
	void	*mlx;

	mlx = mlx_init();
	if (!mlx)
		error_exit("Failed to initialize mlx");
	map->player.moves = 0;
	map->player.x = -1;
	map->player.y = -1;
	map->collectibles = NULL;
	map->num_collectibles = 0;
	draw_game(map);
	mlx_key_hook(mlx_win, &move_player, map);
	mlx_hook(mlx_win, 33, 1L << 17, &cleanup_game, map);
	mlx_loop(mlx);
}

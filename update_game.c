/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engirald <engirald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:41:17 by engirald          #+#    #+#             */
/*   Updated: 2023/03/30 20:41:19 by engirald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	update_game(t_map *map)
{
	if (map->grid[map->player.y][map->player.x] == 'C')
	{
		map->grid[map->player.y][map->player.x] = '0';
		map->player.moves++;
		map->num_collectibles--;
		if (map->num_collectibles == 0)
		{
			ft_putendl_fd("Congratulations! You have collected all the collectibles.", 1);
			ft_putendl_fd("Exiting game...", 1);
			cleanup_game(map);
			exit(0);
		}
	}
}

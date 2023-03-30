/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engirald <engirald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:40:13 by engirald          #+#    #+#             */
/*   Updated: 2023/03/30 20:40:19 by engirald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	move_player(int keycode, t_map *map)
{
	int	new_x;
	int	new_y;

	new_x = map->player.x;
	new_y = map->player.y;
	if (keycode == KEY_UP)
		new_y--;
	else if (keycode == KEY_DOWN)
		new_y++;
	else if (keycode == KEY_LEFT)
		new_x--;
	else if (keycode == KEY_RIGHT)
		new_x++;
	if (map->grid[new_y][new_x] == '1')
		return ;
	else if (map->grid[new_y][new_x] == 'E')
	{
		if (map->num_collectibles == 0)
			exit_game(map, 0);
		else
			return ;
	}
	else if (map->grid[new_y][new_x] == 'C')
	{
		map->num_collectibles--;
		map->grid[new_y][new_x] = '0';
	}
	map->player.moves++;
	map->player.x = new_x;
	map->player.y = new_y;
}

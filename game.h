/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engirald <engirald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:57:55 by engirald          #+#    #+#             */
/*   Updated: 2023/03/30 20:00:21 by engirald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h> 
# include <mlx.h> 
# include "libft.h" 

# define TILE_SIZE 32 

typedef struct	s_player
{
	int			x; 
	int			y; 
	int			moves; 
}				t_player;

typedef struct	s_collectible
{
	int			x; 
	int			y; 
}				t_collectible;

typedef struct	s_map
{
	int			width; 
	int			height; 
	char		**grid; 
	t_player	player; 
	t_collectible	*collectibles; 
	int			num_collectibles; 
}				t_map;

// function prototypes
void		parse_map(char *filename, t_map *map);
void		init_game(t_map *map);
void		draw_game(t_map *map);
void		move_player(int keycode, t_map *map);
void		update_game(t_map *map);
void		cleanup_game(t_map *map);
void		error_exit(char *message);

#endif





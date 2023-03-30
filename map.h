/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engirald <engirald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:04:59 by engirald          #+#    #+#             */
/*   Updated: 2023/03/30 20:06:41 by engirald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

#ifndef MAP_H
# define MAP_H

# define VALID_CHARS "01CEPN"

typedef struct  s_map
{
	int		width;
	int		height;
	char	**matrix;
}				t_map;

int				parse_map(char *file_path, t_map *map);

#endif
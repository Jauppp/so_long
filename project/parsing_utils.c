/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:17:48 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/02/01 17:56:15 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_row_is_wall(char *map)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(map) - 1;
	while (i < len)
	{
		if (map[i] != '1')
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

void	is_item_trapped(char **map, size_t i, size_t j)
{
	while (map[i][j] != '1'&& map[i][j] != 'x' && map[i][j] != 'E')
	{
		map[i][j] = 'x';
		is_item_trapped(map, i + 1, j);
		is_item_trapped(map, i - 1, j);
		is_item_trapped(map, i, j + 1);
		is_item_trapped(map, i, j - 1);
	}
}

void	is_player_trapped(char **map, size_t i, size_t j)
{
	while (map[i][j] != '1'&& map[i][j] != 'x')
	{
		map[i][j] = 'x';
		is_player_trapped(map, i + 1, j);
		is_player_trapped(map, i - 1, j);
		is_player_trapped(map, i, j + 1);
		is_player_trapped(map, i, j - 1);
	}
}

size_t	count_collectibles(char **map)
{
	size_t	i;
	size_t	j;
	size_t	collectibles;

	i = 0;
	collectibles = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				collectibles++;
			j++;
		}
		i++;
	}
	return (collectibles);
}


t_coor	find_sprite_coordinates(char **map, char sprite, t_coor coor)
{
	if (coor.i != 0 && coor.j != 0)
		coor.j++;
	while (map[coor.i])
	{
		if (coor.j >= ft_strlen(map[coor.i]))
			coor.j = 0;
		while (map[coor.i][coor.j])
		{
			if (map[coor.i][coor.j] == sprite)
				return (coor);
			coor.j++;
		}
		coor.i++;
	}
	return (coor);
}

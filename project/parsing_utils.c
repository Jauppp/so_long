/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:17:48 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/02/07 15:54:07 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_sprite_trapped(char **map, size_t i, size_t j)
{
	while (map[i][j] != '1' && map[i][j] != 'v')
	{
		if (map[i][j] == 'E')
		{
			map[i][j] = 'v';
			return ;
		}
		map[i][j] = 'v';
		is_sprite_trapped(map, i + 1, j);
		is_sprite_trapped(map, i - 1, j);
		is_sprite_trapped(map, i, j + 1);
		is_sprite_trapped(map, i, j - 1);
	}
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

int	map_extension_is_valid(char *str)
{
	size_t	i;
	size_t	len;

	i = ft_strlen(str) - 1;
	len = i;
	while (i >= len - 4)
	{
		if (i == len && str[i] != 'r')
			return (FAILURE);
		else if (i == len - 1 && str[i] != 'e')
			return (FAILURE);
		else if (i == len - 2 && str[i] != 'b')
			return (FAILURE);
		else if (i == len - 3 && str[i] != '.')
			return (FAILURE);
		i--;
	}
	return (SUCCESS);
}

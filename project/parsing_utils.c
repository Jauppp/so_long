/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:17:48 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/01/31 18:36:00 by cdomet-d         ###   ########lyon.fr   */
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

int	is_sprite_trapped(char **map, t_coor coor, size_t *count)
{
	if (map[coor.i][coor.j] == '1')
		return (ERR);
	else if (map[coor.i][coor.j] == '0' || map[coor.i][coor.j] == 'C' || \
			map[coor.i][coor.j] == 'E')
		return (ERR);
	map[coor.i][coor.j] = 'x';
	if ()

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
		if (coor.j == ft_strlen(map[coor.i]))
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

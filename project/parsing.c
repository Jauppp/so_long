/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:48:39 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/01/31 14:46:02 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_is_rectangular(char **map)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(map[i]);
	while (map[++i])
	{
		if (ft_strlen(map[i]) != len)
			error_exit(map, 0, ERR, "Error\nMap is not rectangular");
	}
}

void	map_is_closed(char **map)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(map[i]) - 1;
	while (map[i])
	{
		if (map[i][0] != '1')
			error_exit(map, 0, ERR, "Error\nMap is not walled in");
		if (map[i][len - 1] != '1')
			error_exit(map, 0, ERR, "Error\nMap is not walled in");
		i++;
	}
	i--;
	if (!check_row_is_wall(map[0]) || !check_row_is_wall(map[i]))
		error_exit(map, 0, ERR, "Error\nMap is not walled in");
}

void	map_has_one_exit(char **map)
{
	Bool	exit;
	size_t	i;
	size_t	j;

	i = 0;
	exit = False;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
			{
				if (exit == True)
					error_exit(map, 0, ERR, "Error\nMap has multiple exits");
				else
					exit = True;
			}
			j++;
		}
		i++;
	}
	if (exit == False)
		error_exit(map, 0, ERR, "Error\nMap has no exit");
}

void	map_has_one_start_position(char **map)
{
	Bool	start;
	size_t	i;
	size_t	j;

	i = 0;
	start = False;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				if (start == True)
					error_exit(map, 0, ERR, "Error\nMap has multiple starts");
				else
					start = True;
			}
			j++;
		}
		i++;
	}
	if (start == False)
		error_exit(map, 0, ERR, "Error\nMap has no start");
}

void	map_has_collectible(char **map)
{
	Bool	collectible;
	size_t	i;
	size_t	j;

	i = 0;
	collectible = False;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
			{
				collectible = True;
				break ;
			}
			j++;
		}
		i++;
	}
	if (collectible == False)
		error_exit(map, 0, ERR, "Error\nMap has no collectible");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:48:39 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/02/09 14:35:18 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_is_rectangular(char **map)
{
	size_t	i;
	size_t	len;
	size_t	matlen;

	i = 0;
	matlen = ft_matlen(map);
	if (matlen < 3)
		parse_err(map, NULL, "Error\nMap is too small");
	len = ft_strlen_n(map[i]);
	while (i < matlen)
	{
		if (ft_strlen_n(map[i]) != len)
			parse_err(map, NULL, "Error\nMap is not rectangular");
		i++;
	}
}

void	map_is_closed(char **map)
{
	size_t	i;
	size_t	len;
	size_t	matlen;

	i = 0;
	matlen = ft_matlen(map);
	len = ft_strlen(map[i]);
	while (i < matlen - 1)
	{
		if (map[i][0] != '1')
			parse_err(map, NULL, "Error\nMap is not walled in");
		if (map[i][len - 2] != '1')
			parse_err(map, NULL, "Error\nMap is not walled in");
		i++;
	}
	if (!check_row_is_wall(map[0]) || !check_row_is_wall(map[i]))
		parse_err(map, NULL, "Error\nMap is not walled in");
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
					parse_err(map, NULL, "Error\nMap has more than one start");
				else
					start = True;
			}
			j++;
		}
		i++;
	}
	if (start == False)
		parse_err(map, NULL, "Error\nMap has no start");
}

int	map_has_collectible(char **map)
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
				collectible = True;
			j++;
		}
		i++;
	}
	if (collectible == False)
		return (FAILURE);
	else
		return (SUCCESS);
}

int	map_has_one_exit(char **map)
{
	Bool	exit;
	size_t	i;
	size_t	j;

	i = 0;
	exit = False;
	while (map[++i])
	{
		j = 0;
		while (map[i][++j])
		{
			if (map[i][j] == 'E')
			{
				if (exit == True)
					return (FAILURE);
				else
					exit = True;
			}
		}
	}
	if (exit == False)
		return (FAILURE);
	else
		return (SUCCESS);
}

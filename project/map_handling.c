/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:06:08 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/01/31 14:44:09 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map_stdin(char **map)
{
	size_t	row;
	char	*new_row;

	row = 0;
	new_row = get_next_line(STDIN_FILENO);
	if (errno)
		error_exit(map, row, errno, NULL);
	while (new_row)
	{
		map[row] = new_row;
		row++;
		if (row == MAX_ROW - 1)
			error_exit(map, row, EXIT_FAILURE, NULL);
		new_row = get_next_line(STDIN_FILENO);
		if (errno)
			error_exit(map, row, errno, NULL);
	}
	map[row] = 0;
}

void	init_map_fd(char **map, char *arg)
{
	size_t	row;
	char	*new_row;
	int		fd;

	row = 0;
	fd = open(arg, O_RDONLY);
	if (errno)
		error_exit(map, row, errno, NULL);
	new_row = get_next_line(fd);
	if (errno)
		error_exit(map, row, errno, NULL);
	while (new_row)
	{
		map[row] = new_row;
		row++;
		if (row == MAX_ROW - 1)
			error_exit(map, row, EXIT_FAILURE, NULL);
		new_row = get_next_line(fd);
		if (errno)
			error_exit(map, row, errno, NULL);
	}
	close(fd);
	map[row] = 0;
}

void	is_map_valid(char **map)
{
	map_is_rectangular(map);
	map_is_closed(map);
	map_has_one_exit(map);
	map_has_one_start_position(map);
	map_has_collectible(map);
}


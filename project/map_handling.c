/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:06:08 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/01/30 16:38:35 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map_stdin(char **map)
{
	size_t	row;
	char	*new_row;

	row = 0;
	new_row = get_next_line(STDIN_FILENO);
	if (!new_row)
		free_and_exit(map, ERROR);
	while (new_row)
	{
		map[row] = new_row;
		row++;
		if (row == ROW_ERROR)
		{
			map[ROW_ERROR] = 0;
			printf("Error in init_map_stdin: map is over 150 lines\n");
			free_and_exit(map, EXIT_FAILURE);
		}
		new_row = get_next_line(STDIN_FILENO);
		if (errno)
			error_exit(map, row, errno);
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
		error_exit(map, row, errno);
	new_row = get_next_line(fd);
	if (errno)
		error_exit(map, row, errno);
	while (new_row)
	{
		map[row] = new_row;
		row++;
		if (row == ROW_ERROR)
		{
			map[ROW_ERROR] = 0;
			printf("Error in init_map_stdin: map is over 150 lines\n");
			free_and_exit(map, EXIT_FAILURE);
		}
		new_row = get_next_line(fd);
		if (errno)
			error_exit(map, row, errno);
	}
	close(fd);
	map[row] = 0;
}

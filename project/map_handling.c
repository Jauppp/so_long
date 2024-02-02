/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:06:08 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/02/02 17:29:16 by cdomet-d         ###   ########lyon.fr   */
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
		mem_err(map, row, errno);
	while (new_row)
	{
		map[row] = new_row;
		row++;
		if (row == MAX_ROW - 1)
			mem_err(map, row, EXIT_FAILURE);
		new_row = get_next_line(STDIN_FILENO);
		if (errno)
			mem_err(map, row, errno);
	}
	map[row] = NULL;
}

void	init_map_fd(char **map, char *arg)
{
	size_t	row;
	char	*new_row;
	int		fd;

	row = 0;
	fd = open(arg, O_RDONLY);
	if (errno)
		mem_err(map, row, errno);
	new_row = get_next_line(fd);
	if (errno)
		mem_err(map, row, errno);
	while (new_row)
	{
		map[row] = new_row;
		row++;
		if (row == MAX_ROW - 1)
			mem_err(map, row, EXIT_FAILURE);
		new_row = get_next_line(fd);
		if (errno)
			mem_err(map, row, errno);
	}
	close(fd);
	map[row] = NULL;
}

char **copy_tab(char **map)
{
	size_t	matlen;
	size_t	i;
	char 	**map_cpy;
	
	matlen = ft_matlen(map);
	map_cpy = malloc((matlen + 1) * sizeof(map_cpy));
	if (errno)
		mem_err(map, 0, errno);
	i = -1;
	while (++i < matlen)
	{
		map_cpy[i] = ft_strdup(map[i]);
		if (errno)
			mem_err(map, 0, errno);
	}
	map_cpy[matlen] = NULL;
	return (map_cpy);
}

void	is_map_valid(char **map)
{
	char 	**map_cpy;
	t_coor	coor;
	
	coor.i = 0;
	coor.j = 0;
	map_is_rectangular(map);
	map_is_closed(map);
	map_has_one_start_position(map);
	if (!map_has_one_exit(map))
		parse_err(map, NULL, "Error\nMap doesn't have exactly one exit");
	if (!map_has_collectible(map))
		parse_err(map, NULL, "Error\nMap has no items to collect");
	map_cpy = copy_tab(map);
	if (errno)
		mem_err(map, 0, errno);
	coor = find_sprite_coordinates(map_cpy, 'P', coor);
	is_sprite_trapped(map_cpy, coor.i, coor.j);
	print_map(map_cpy);
	if (map_has_one_exit(map_cpy))
		parse_err(map, map_cpy, "Error\nPlayer cannot reach the exit :(");
	if (map_has_collectible(map_cpy))
		parse_err(map, map_cpy, "Error\nPlayer cannot reach all collectibles :(");
	free_double_tab(map_cpy);
}
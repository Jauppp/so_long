/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:06:08 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/02/12 15:47:42 by cdomet-d         ###   ########lyon.fr   */
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
	if (ft_strlen_n(new_row) >= MAX_COL)
		parse_err(map, NULL, "Error\nMap is too wide. Max is 25 columns!");
	while (new_row)
	{
		map[row] = new_row;
		row++;
		if (row == MAX_ROW - 1)
			parse_err(map, NULL, "Error\nMap has too many lines. Max is 15 !");
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
	if (ft_strlen_n(new_row) >= MAX_COL)
		parse_err(map, NULL, "Error\nMap is too wide. Max is 25 columns!");
	if (errno)
		mem_err(map, row, errno);
	while (new_row)
	{
		map[row] = new_row;
		row++;
		if (row == MAX_ROW - 1)
			parse_err(map, NULL, "Error\nMap has too many lines. Max is 15 !");
		new_row = get_next_line(fd);
		if (errno)
			mem_err(map, 0, errno);
	}
	close(fd);
	map[row] = NULL;
}

char	**copy_tab(char **map)
{
	size_t	matlen;
	size_t	i;
	char	**map_cpy;

	map_cpy = NULL;
	matlen = ft_matlen(map);
	map_cpy = malloc((matlen + 1) * sizeof(map_cpy));
	if (errno)
		parse_err(map, map_cpy, strerror(errno));
	i = -1;
	while (++i < matlen)
	{
		map_cpy[i] = ft_strdup(map[i]);
		if (errno)
			parse_err(map, map_cpy, strerror(errno));
	}
	map_cpy[matlen] = NULL;
	return (map_cpy);
}

void	is_map_valid(char **map)
{
	char	**map_cpy;
	t_coor	coor;

	coor.i = 0;
	coor.j = 0;
	map_cpy = NULL;
	char_is_valid(map);
	map_is_rectangular(map);
	map_is_closed(map);
	map_has_one_start_position(map);
	if (!map_has_one_exit(map))
		parse_err(map, NULL, "Error\nMap doesn't have exactly one exit");
	if (!map_has_collectible(map))
		parse_err(map, NULL, "Error\nMap has no items to collect");
	map_cpy = copy_tab(map);
	if (errno)
		parse_err(map, map_cpy, strerror(errno));
	coor = find_sprite_coordinates(map_cpy, 'P', coor);
	is_sprite_trapped(map_cpy, coor.i, coor.j);
	if (map_has_one_exit(map_cpy))
		parse_err(map, map_cpy, "Error\nPlayer can't reach the exit :(");
	if (map_has_collectible(map_cpy))
		parse_err(map, map_cpy, "Error\nPlayer can't reach all items :(");
	free_double_tab(map_cpy);
}

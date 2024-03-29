/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:15:28 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/02/16 10:58:33 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mem_err(char **map, size_t row, int error_code)
{
	if (row)
		map[row] = 0;
	if (error_code == MAP_ERR)
		ft_printf("Error\nMap is too large. Max : 15 * 25\n");
	else
		strerror(error_code);
	free_tab(map);
	exit(EXIT_FAILURE);
}

void	parse_err(char **map, char **map_cpy, char *error_message)
{
	if (error_message)
		ft_printf("%s\n", error_message);
	if (map)
		free_tab(map);
	if (map_cpy)
		free_double_tab(map_cpy);
	exit(EXIT_FAILURE);
}

void	mlx_error(t_display display, char *error_message)
{
	if (error_message)
		ft_printf("%s\n", error_message);
	free_double_tab(display.map);
	free_mlx(display);
	exit(EXIT_FAILURE);
}

void	print_error(int error_code, char *error_message)
{
	if (error_message)
		ft_printf("%s\n", error_message);
	if (error_code)
		strerror(error_code);
	exit(EXIT_FAILURE);
}

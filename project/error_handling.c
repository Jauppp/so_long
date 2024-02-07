/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:15:28 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/02/07 21:23:26 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mem_err(char **map, size_t row, int error_code)
{
	if (row)
		map[row] = 0;
	ft_printf("Error : %s\n", strerror(error_code));
	free_and_exit(map, error_code);
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
	free_mlx(display);
	exit(EXIT_FAILURE);
}

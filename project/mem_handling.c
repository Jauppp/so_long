/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:29:41 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/02/07 11:52:22 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_and_exit(char **map, int error_code)
{
	size_t	i;

	if (!map || !*map)
		exit(STDOUT_FILENO);
	i = 0;
	while (map[i])
		free(map[i++]);
	if (!error_code)
		exit(EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);
}

void	free_double_tab(char **double_tab)
{
	size_t	i;

	i = 0;
	if (!double_tab || !*double_tab)
		return ;
	while (double_tab[i])
		free(double_tab[i++]);
	free(double_tab);
	double_tab = NULL;
	return ;
}

void	free_mlx(t_display display)
{
	if (display.bg)
		mlx_destroy_image(display.mlx_id, display.bg);
	if (display.exit)
		mlx_destroy_image(display.mlx_id, display.exit);
	if (display.item)
		mlx_destroy_image(display.mlx_id, display.item);
	if (display.player)
		mlx_destroy_image(display.mlx_id, display.player);
	if (display.wall)
		mlx_destroy_image(display.mlx_id, display.wall);
	if (display.win_id)
		mlx_destroy_window(display.mlx_id, display.win_id);
	if (display.mlx_id)
		mlx_destroy_display(display.mlx_id);
	free(display.mlx_id);
}

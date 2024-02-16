/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:29:41 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/02/16 10:26:46 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_tab(char **map)
{
	size_t	i;

	i = 0;
	if (!map)
		exit(EXIT_FAILURE);
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	map = NULL;
}

void	free_and_exit(char **map, int error_code)
{
	free_double_tab(map);
	if (!error_code)
		exit(EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);
}

void	free_double_tab(char **double_tab)
{
	if (!double_tab)
		return ;
	free_tab(double_tab);
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
	if (display.exit_1)
		mlx_destroy_image(display.mlx_id, display.exit_1);
	if (display.item)
		mlx_destroy_image(display.mlx_id, display.item);
	if (display.player)
		mlx_destroy_image(display.mlx_id, display.player);
	if (display.player_1)
		mlx_destroy_image(display.mlx_id, display.player_1);
	if (display.player_2)
		mlx_destroy_image(display.mlx_id, display.player_2);
	if (display.wall)
		mlx_destroy_image(display.mlx_id, display.wall);
	if (display.win_screen)
		mlx_destroy_image(display.mlx_id, display.win_screen);
	if (display.win_id)
		mlx_destroy_window(display.mlx_id, display.win_id);
	if (display.mlx_id)
		mlx_destroy_display(display.mlx_id);
	free(display.mlx_id);
}

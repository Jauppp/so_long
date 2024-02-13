/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 09:38:43 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/02/13 13:19:50 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_display(t_display *display)
{
	dis_null_init(display);
	display->mlx_id = mlx_init();
	if (!display->mlx_id)
		mlx_error(*display, "Error\nCould not initialize mlx");
	display->win_id = mlx_new_window(display->mlx_id, display->window.w, \
		display->window.h, "so_long");
	if (!display->win_id)
		mlx_error(*display, "Error\nCould not initialize window");
	display->win_screen = mlx_xpm_file_to_image(display->mlx_id, \
		"sprites/win_screen.xpm", &display->sprite.w, &display->sprite.h);
	if (!display->win_screen)
		mlx_error(*display, "Error\nCould not fetch win screen");
}

void	init_decor(t_display *display)
{
	display->bg = mlx_xpm_file_to_image(display->mlx_id, \
		"sprites/bg.xpm", &display->sprite.w, &display->sprite.h);
	if (!display->bg)
		mlx_error(*display, "Error\nCould not fetch background");
	display->wall = mlx_xpm_file_to_image(display->mlx_id, \
		"sprites/wall.xpm", &display->sprite.w, &display->sprite.h);
	if (!display->wall)
		mlx_error(*display, "Error\nCould not fetch wall");
	display->item = mlx_xpm_file_to_image(display->mlx_id, \
		"sprites/items.xpm", &display->sprite.w, &display->sprite.h);
	if (!display->item)
		mlx_error(*display, "Error\nCould not fetch item");
	display->exit = mlx_xpm_file_to_image(display->mlx_id, \
		"sprites/exit.xpm", &display->sprite.w, &display->sprite.h);
	if (!display->exit)
		mlx_error(*display, "Error\nCould not fetch exit");
	display->exit_1 = mlx_xpm_file_to_image(display->mlx_id, \
		"sprites/exit_02.xpm", &display->sprite.w, &display->sprite.h);
	if (!display->exit_1)
		mlx_error(*display, "Error\nCould not fetch exit");
}

void	init_player(t_display *display)
{
	display->player = mlx_xpm_file_to_image(display->mlx_id, \
		"sprites/player.xpm", &display->sprite.w, &display->sprite.h);
	if (!display->player)
		mlx_error(*display, "Error\nCould not fetch player");
	display->player_1 = mlx_xpm_file_to_image(display->mlx_id, \
		"sprites/player_01.xpm", &display->sprite.w, &display->sprite.h);
	if (!display->player_1)
		mlx_error(*display, "Error\nCould not fetch player");
	display->player_2 = mlx_xpm_file_to_image(display->mlx_id, \
		"sprites/player_02.xpm", &display->sprite.w, &display->sprite.h);
	if (!display->player_2)
		mlx_error(*display, "Error\nCould not fetch player");
}

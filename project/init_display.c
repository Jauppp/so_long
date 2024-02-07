/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 09:38:43 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/02/08 00:18:08 by cdomet-d         ###   ########lyon.fr   */
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
}

void	init_decor(t_display *display)
{
	display->bg = mlx_xpm_file_to_image(display->mlx_id, \
		"../sprites/bg.xpm", &display->sprite.w, &display->sprite.h);
	if (!display->bg)
		mlx_error(*display, "Error\nCould not fetch sprite");
	display->wall = mlx_xpm_file_to_image(display->mlx_id, \
		"../sprites/wall.xpm", &display->sprite.w, &display->sprite.h);
	if (!display->wall)
		mlx_error(*display, "Error\nCould not fetch sprite");
	display->item = mlx_xpm_file_to_image(display->mlx_id, \
		"../sprites/items.xpm", &display->sprite.w, &display->sprite.h);
	if (!display->item)
		mlx_error(*display, "Error\nCould not fetch sprite");
	display->exit = mlx_xpm_file_to_image(display->mlx_id, \
		"../sprites/exit.xpm", &display->sprite.w, &display->sprite.h);
	if (!display->exit)
		mlx_error(*display, "Error\nCould not fetch sprite");
	display->exit_open = mlx_xpm_file_to_image(display->mlx_id, \
		"../sprites/exit_02.xpm", &display->sprite.w, &display->sprite.h);
	if (!display->exit_open)
		mlx_error(*display, "Error\nCould not fetch sprite");
}
void	init_player(t_display *display)
{
	display->player = mlx_xpm_file_to_image(display->mlx_id, \
		"../sprites/player.xpm", &display->sprite.w, &display->sprite.h);
	if (!display->player)
		mlx_error(*display, "Error\nCould not fetch sprite");
	display->player_dance_1 = mlx_xpm_file_to_image(display->mlx_id, \
		"../sprites/player_01.xpm", &display->sprite.w, &display->sprite.h);
	if (!display->player_dance_1)
		mlx_error(*display, "Error\nCould not fetch sprite");
	display->player_dance_2 = mlx_xpm_file_to_image(display->mlx_id, \
		"../sprites/player_02.xpm", &display->sprite.w, &display->sprite.h);
	if (!display->player_dance_2)
		mlx_error(*display, "Error\nCould not fetch sprite");
}


void	init_coordinate(t_display *display)
{
	display->sprite_coo.i = display->sprite.w * display->coo.i;
	display->sprite_coo.j = display->sprite.h * display->coo.j;
}

void	load_map(t_display display)
{
	while (display.map[display.coo.i])
	{
		display.coo.j = 0;
		while (display.map[display.coo.i][display.coo.j])
		{
			init_coordinate(&display);
			if (display.map[display.coo.i][display.coo.j] == '1')
				mlx_put_image_to_window(display.mlx_id, display.win_id, \
					display.wall, display.sprite_coo.j, display.sprite_coo.i);
			else if (display.map[display.coo.i][display.coo.j] == 'C')
				mlx_put_image_to_window(display.mlx_id, display.win_id, \
					display.item, display.sprite_coo.j, display.sprite_coo.i);
			else if (display.map[display.coo.i][display.coo.j] == 'P')
				mlx_put_image_to_window(display.mlx_id, display.win_id, \
					display.player, display.sprite_coo.j, display.sprite_coo.i);
			else if (display.map[display.coo.i][display.coo.j] == 'E')
				mlx_put_image_to_window(display.mlx_id, display.win_id, \
					display.exit, display.sprite_coo.j, display.sprite_coo.i);
			else if (display.map[display.coo.i][display.coo.j] == 'e')
				mlx_put_image_to_window(display.mlx_id, display.win_id, \
					display.exit_open, display.sprite_coo.j, display.sprite_coo.i);
			else if (display.map[display.coo.i][display.coo.j] == 'p')
				mlx_put_image_to_window(display.mlx_id, display.win_id, \
					display.player_dance_1, display.sprite_coo.j, display.sprite_coo.i);
			else
				mlx_put_image_to_window(display.mlx_id, display.win_id, \
					display.bg, display.sprite_coo.j, display.sprite_coo.i);
			display.coo.j++;
		}
		display.coo.i++;
	}
}

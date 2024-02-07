/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 09:38:43 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/02/07 11:58:00 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_display(t_display *display, char **map)
{
	dis_null_init(display, map);
	display->mlx_id = mlx_init();
	if (!display->mlx_id)
		mlx_error(map, *display, "Error\nCould not initialize mlx");
	display->win_id = mlx_new_window(display->mlx_id, display->window.w, \
		display->window.h, "so_long");
	if (!display->win_id)
		mlx_error(map, *display, "Error\nCould not initialize window");
}

void	init_sprites(t_display *display, char **map)
{
	display->bg = mlx_xpm_file_to_image(display->mlx_id, \
		"../sprites/bg.xpm", &display->sprite.w, &display->sprite.h);
	if (!display->bg)
		mlx_error(map, *display, "Error\nCould not fetch sprite");
	display->wall = mlx_xpm_file_to_image(display->mlx_id, \
		"../sprites/wall.xpm", &display->sprite.w, &display->sprite.h);
	if (!display->wall)
		mlx_error(map, *display, "Error\nCould not fetch sprite");
	display->item = mlx_xpm_file_to_image(display->mlx_id, \
		"../sprites/items.xpm", &display->sprite.w, &display->sprite.h);
	if (!display->item)
		mlx_error(map, *display, "Error\nCould not fetch sprite");
	display->player = mlx_xpm_file_to_image(display->mlx_id, \
		"../sprites/player.xpm", &display->sprite.w, &display->sprite.h);
	if (!display->player)
		mlx_error(map, *display, "Error\nCould not fetch sprite");
	display->exit = mlx_xpm_file_to_image(display->mlx_id, \
		"../sprites/exit.xpm", &display->sprite.w, &display->sprite.h);
	if (!display->exit)
		mlx_error(map, *display, "Error\nCould not fetch sprite");
}

void	init_coordinate(t_coor *img, t_display display)
{
	img->i = display.sprite.w * display.coo.i;
	img->j = display.sprite.h * display.coo.j;
}

void	load_map(t_display display, t_coor img, char **map)
{
	while (map[display.coo.i])
	{
		display.coo.j = 0;
		while (map[display.coo.i][display.coo.j])
		{
			init_coordinate(&img, display);
			if (map[display.coo.i][display.coo.j] == '1')
				mlx_put_image_to_window(display.mlx_id, display.win_id, \
					display.wall, img.j, img.i);
			else if (map[display.coo.i][display.coo.j] == 'C')
				mlx_put_image_to_window(display.mlx_id, display.win_id, \
					display.item, img.j, img.i);
			else if (map[display.coo.i][display.coo.j] == 'P')
				mlx_put_image_to_window(display.mlx_id, display.win_id, \
					display.player, img.j, img.i);
			else if (map[display.coo.i][display.coo.j] == 'E')
				mlx_put_image_to_window(display.mlx_id, display.win_id, \
					display.exit, img.j, img.i);
			else
				mlx_put_image_to_window(display.mlx_id, display.win_id, \
					display.bg, img.j, img.i);
			display.coo.j++;
		}
		display.coo.i++;
	}
}

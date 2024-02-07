/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:37:37 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/02/08 00:25:44 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_display *display)
{
	t_coor	player;
	int		anim;
	
	anim = 0;
	player.i = 0;
	player.j = 0;
	player = find_sprite_coordinates(display->map, 'P', player);
	printf("keycode = %d\n", keycode);
	if (keycode == ESC)
		mlx_loop_end(display->mlx_id);
	if (keycode == 'w')
	{
		if (display->map[player.i - 1][player.j] != '1')
		{
			if (display->map[player.i - 1][player.j] == 'E')
			{
				display->map[player.i - 1][player.j] = 'e';
				load_map(*display);
				while (anim < 1800)
				{
					display->map[player.i][player.j] = 'p';
					load_map(*display);
					display->map[player.i][player.j] = 'P';
					load_map(*display);
					anim++;
				}
			mlx_loop_end(display->mlx_id);
			}
			display->map[player.i - 1][player.j] = 'P';
			display->map[player.i][player.j] = '0';
			load_map(*display);
		}
	}
	if (keycode == 'a')
	{
		if (display->map[player.i][player.j - 1] != '1')
		{
			if (display->map[player.i][player.j - 1] == 'E')
			{
				display->map[player.i][player.j - 1] = 'e';
				load_map(*display);
				while (anim < 1800)
				{
					display->map[player.i][player.j] = 'p';
					load_map(*display);
					display->map[player.i][player.j] = 'P';
					load_map(*display);
					anim++;
				}
				mlx_loop_end(display->mlx_id);
			}
			display->map[player.i][player.j - 1] = 'P';
			display->map[player.i][player.j] = '0';
			load_map(*display);
		}
	}
	if (keycode == 'd')
	{
		if (display->map[player.i][player.j + 1] != '1')
		{
			if (display->map[player.i][player.j + 1] == 'E')
			{
				display->map[player.i][player.j + 1] = 'e';
				load_map(*display);
				while (anim < 1800)
				{
					display->map[player.i][player.j] = 'p';
					load_map(*display);
					display->map[player.i][player.j] = 'P';
					load_map(*display);
					anim++;
				}
				mlx_loop_end(display->mlx_id);
			}
			display->map[player.i][player.j + 1] = 'P';
			display->map[player.i][player.j] = '0';
			load_map(*display);
		}
	}
	if (keycode == 's')
	{
		if (display->map[player.i + 1][player.j] != '1')
		{
			if (display->map[player.i + 1][player.j] == 'E')
			{
				display->map[player.i + 1][player.j] = 'e';
				load_map(*display);
				while (anim < 1800)
				{
					display->map[player.i][player.j] = 'p';
					load_map(*display);
					display->map[player.i][player.j] = 'P';
					load_map(*display);
					anim++;
				}
				mlx_loop_end(display->mlx_id);
			}
			display->map[player.i + 1][player.j] = 'P';
			display->map[player.i][player.j] = '0';
			load_map(*display);
		}
	}
	return (0);
}

int	mouse_hook(int button, int x, int y, t_display *display)
{
	printf("x = %d || y = %d\n", x, y);
	if (button == 1 && x == 600 && y == 600)
		mlx_loop_end(display->mlx_id);
	return (0);
}

int	close_win(t_display *display)
{
	mlx_loop_end(display->mlx_id);
	return (0);
}

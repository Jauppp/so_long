/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_screen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:11:00 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/02/12 14:04:02 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	player_refresh(t_display display)
{
	init_coordinate(&display);
	if (display.map[display.coo.i][display.coo.j] == 'p')
		mlx_put_image_to_window(display.mlx_id, display.win_id, \
		display.player_1, display.sprite_coo.j, display.sprite_coo.i);
	else if (display.map[display.coo.i][display.coo.j] == 'd')
		mlx_put_image_to_window(display.mlx_id, display.win_id, \
		display.player_2, display.sprite_coo.j, display.sprite_coo.i);
}

void	player_anim(t_display display)
{
	while (display.anim < 60000)
	{
		if (display.anim % 2 == 0)
		{
			display.map[display.coo.i][display.coo.j] = 'p';
			player_refresh(display);
		}
		else
		{
			display.map[display.coo.i][display.coo.j] = 'd';
			player_refresh(display);
		}
		display.anim++;
	}
}

void	load_win_screen(t_display display)
{
	t_coor	center;

	clear_map(&display);
	load_map(display);
	find_map_center(&display, &center);
	mlx_put_image_to_window(display.mlx_id, display.win_id, \
				display.win_screen, center.j * 160, center.i * 160);
}

void	open_exit(t_display display)
{
	load_move(display);
	display_win_message(display);
	player_anim(display);
	load_win_screen(display);
	player_anim(display);
	mlx_loop_end(display.mlx_id);
}

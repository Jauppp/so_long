/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:37:37 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/02/12 13:57:53 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_display *display)
{
	null_init_coo(&display->coo);
	clear_player_move(display);
	display_player_move(display);
	display->coo = find_sprite_coordinates(display->map, 'P', display->coo);
	if (keycode == ESC)
		mlx_loop_end(display->mlx_id);
	if (keycode == 'w')
		move_up(display);
	if (keycode == 'a')
		move_left(display);
	if (keycode == 'd')
		move_right(display);
	if (keycode == 's')
		move_down(display);
	return (0);
}

int	close_win(t_display *display)
{
	mlx_loop_end(display->mlx_id);
	return (0);
}

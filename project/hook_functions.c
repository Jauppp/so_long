/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:37:37 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/02/09 16:43:18 by cdomet-d         ###   ########lyon.fr   */
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

int	mouse_hook(int button, int x, int y, t_display *display)
{
	if (button == 1 && x == 600 && y == 600)
		mlx_loop_end(display->mlx_id);
	return (0);
}

int	close_win(t_display *display)
{
	mlx_loop_end(display->mlx_id);
	return (0);
}

void	display_player_move(t_display *display)
{
	char	*moves;

	errno = 0;
	moves = ft_itoa(display->move_counter);
	if (errno)
		mem_err(display->map, 0, errno);
	mlx_string_put(display->mlx_id, display->win_id, 320, 80, 16710368, moves);
	free(moves);
}

void	clear_player_move(t_display *display)
{
	char	*moves;

	errno = 0;
	moves = ft_itoa(display->move_counter - 1);
	if (errno)
		mem_err(display->map, 0, errno);
	mlx_string_put(display->mlx_id, display->win_id, 320, 80, 0, moves);
	free(moves);
}

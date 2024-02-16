/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:08:32 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/02/16 11:33:50 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_player_move(t_display *display)
{
	char	*str;

	errno = 0;
	str = ft_itoa(display->move_counter);
	if (errno)
		mem_err(display->map, 0, errno);
	mlx_string_put(display->mlx_id, display->win_id, 320, 80, WHITE, str);
	free(str);
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

void	display_move_counter(t_display *display)
{
	clear_player_move(display);
	display_player_move(display);
}

void	display_win_message(t_display display)
{
	char	*str;

	errno = 0;
	str = ft_itoa(display.move_counter - 1);
	if (errno)
		mem_err(display.map, 0, errno);
	if (display.window.w <= 480)
	{
		mlx_string_put(display.mlx_id, display.win_id, 160, 120,
			WHITE, "You won in");
		mlx_string_put(display.mlx_id, display.win_id, 230, 120, WHITE, str);
		mlx_string_put(display.mlx_id, display.win_id, 250, 120, WHITE, \
			" moves !!");
	}
	else
	{
		mlx_string_put(display.mlx_id, display.win_id, 480, 80,
			WHITE, "You won in");
		mlx_string_put(display.mlx_id, display.win_id, 560, 80, WHITE, str);
		mlx_string_put(display.mlx_id, display.win_id, 580, 80, WHITE, \
			" moves !!");
	}
	free(str);
}

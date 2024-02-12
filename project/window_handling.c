/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:51:00 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/02/12 14:03:06 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_window(t_display display)
{
	init_display(&display);
	init_decor(&display);
	init_player(&display);
	mlx_string_put(display.mlx_id, display.win_id, 160, 80, WHITE, \
		" <3 Total moves : ");
	mlx_string_put(display.mlx_id, display.win_id, 320, 80, WHITE, "0");
	mlx_hook(display.win_id, 2, (1L << 0), key_hook, &display);
	mlx_hook(display.win_id, 17, (0L), close_win, &display);
	load_map(display);
	mlx_loop(display.mlx_id);
	free_mlx(display);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:51:00 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/02/08 00:15:29 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_window(t_display display)
{
	init_display(&display);
	init_decor(&display);
	init_player(&display);
	init_coordinate(&display);
	mlx_hook(display.win_id, 2, (1L<<0), key_hook, &display);
	mlx_hook(display.win_id, 17, (0L), close_win, &display);
	mlx_hook(display.win_id, 4, ((1L<<2)), mouse_hook, &display);
	load_map(display);
	mlx_loop(display.mlx_id);
	free_mlx(display);
}

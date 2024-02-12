/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:40:12 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/02/12 12:46:52 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_exit(t_display	display)
{
	if (display.map[display.coo.i][display.coo.j] == 'E')
		mlx_put_image_to_window(display.mlx_id, display.win_id, \
		display.exit, display.sprite_coo.j, display.sprite_coo.i);
	else if (display.map[display.coo.i][display.coo.j] == 'e')
		mlx_put_image_to_window(display.mlx_id, display.win_id, \
		display.exit_1, display.sprite_coo.j, display.sprite_coo.i);
}

void	load_player_and_items(t_display	display)
{
	if (display.map[display.coo.i][display.coo.j] == 'P')
		mlx_put_image_to_window(display.mlx_id, display.win_id, \
		display.player, display.sprite_coo.j, display.sprite_coo.i);
	else if (display.map[display.coo.i][display.coo.j] == 'C')
		mlx_put_image_to_window(display.mlx_id, display.win_id, \
		display.item, display.sprite_coo.j, display.sprite_coo.i);
}

void	load_background(t_display	display)
{
	if (display.map[display.coo.i][display.coo.j] == '1')
		mlx_put_image_to_window(display.mlx_id, display.win_id, \
		display.wall, display.sprite_coo.j, display.sprite_coo.i);
	else if (display.map[display.coo.i][display.coo.j] == '0')
		mlx_put_image_to_window(display.mlx_id, display.win_id, \
			display.bg, display.sprite_coo.j, display.sprite_coo.i);
}

void	load_decor(t_display display)
{
	init_coordinate(&display);
	if (display.map[display.coo.i][display.coo.j] == '1')
		mlx_put_image_to_window(display.mlx_id, display.win_id, \
		display.wall, display.sprite_coo.j, display.sprite_coo.i);
	else if (display.map[display.coo.i][display.coo.j] == 'C')
		mlx_put_image_to_window(display.mlx_id, display.win_id, \
		display.item, display.sprite_coo.j, display.sprite_coo.i);
	else if (display.map[display.coo.i][display.coo.j] == 'E')
		mlx_put_image_to_window(display.mlx_id, display.win_id, \
		display.exit, display.sprite_coo.j, display.sprite_coo.i);
	else if (display.map[display.coo.i][display.coo.j] == 'e')
		mlx_put_image_to_window(display.mlx_id, display.win_id, \
		display.exit_1, display.sprite_coo.j, display.sprite_coo.i);
	else if (display.map[display.coo.i][display.coo.j] == '0')
		mlx_put_image_to_window(display.mlx_id, display.win_id, \
			display.bg, display.sprite_coo.j, display.sprite_coo.i);
}

void	load_player(t_display display)
{
	init_coordinate(&display);
	if (display.map[display.coo.i][display.coo.j] == 'P')
		mlx_put_image_to_window(display.mlx_id, display.win_id, \
		display.player, display.sprite_coo.j, display.sprite_coo.i);
	else if (display.map[display.coo.i][display.coo.j] == 'p')
		mlx_put_image_to_window(display.mlx_id, display.win_id, \
		display.player_1, display.sprite_coo.j, display.sprite_coo.i);
	else if (display.map[display.coo.i][display.coo.j] == 'd')
		mlx_put_image_to_window(display.mlx_id, display.win_id, \
		display.player_2, display.sprite_coo.j, display.sprite_coo.i);
}

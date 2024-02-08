/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_to_window.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:13:26 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/02/08 14:34:38 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_map(t_display display)
{
	null_init_coo(&display.coo);
	load_decor(display);
	null_init_coo(&display.coo);
	load_player(display);
}

void	load_decor(t_display display)
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
			else if (display.map[display.coo.i][display.coo.j] == 'E')
				mlx_put_image_to_window(display.mlx_id, display.win_id, \
				display.exit, display.sprite_coo.j, display.sprite_coo.i);
			else if (display.map[display.coo.i][display.coo.j] == 'e')
				mlx_put_image_to_window(display.mlx_id, display.win_id, \
				display.exit_1, display.sprite_coo.j, display.sprite_coo.i);
			else if (display.map[display.coo.i][display.coo.j] == '0')
				mlx_put_image_to_window(display.mlx_id, display.win_id, \
					display.bg, display.sprite_coo.j, display.sprite_coo.i);
			display.coo.j++;
		}
		display.coo.i++;
	}
}

void	load_player(t_display display)
{
	while (display.map[display.coo.i])
	{
		display.coo.j = 0;
		while (display.map[display.coo.i][display.coo.j])
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
			display.coo.j++;
		}
		display.coo.i++;
	}
}

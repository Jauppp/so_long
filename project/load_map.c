/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:13:26 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/02/12 12:47:16 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_map(t_display display)
{
	null_init_coo(&display.coo);
	while (display.map[display.coo.i])
	{
		display.coo.j = 0;
		while (display.map[display.coo.i][display.coo.j])
		{
			load_decor(display);
			load_player(display);
			display.coo.j++;
		}
		display.coo.i++;
	}
}

void	load_move(t_display	display)
{
	t_coor	max;
	int		og_j;

	max.i = (display.coo.i - 1) + 3;
	max.j = (display.coo.j - 1) + 3;
	og_j = display.coo.j - 1;
	display.coo.i = display.coo.i - 1;
	while (display.coo.i < max.i)
	{
		display.coo.j = og_j;
		while (display.coo.j < max.j)
		{
			init_coordinate(&display);
			load_player_and_items(display);
			load_background(display);
			load_exit(display);
			display.coo.j++;
		}
		display.coo.i++;
	}
}

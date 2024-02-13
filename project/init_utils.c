/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:15:29 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/02/13 10:19:48 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	count_collectibles(t_display *display)
{
	while (display->map[display->coo.i])
	{
		display->coo.j = 0;
		while (display->map[display->coo.i][display->coo.j])
		{
			if (display->map[display->coo.i][display->coo.j] == 'C')
				display->item_total++;
			display->coo.j++;
		}
		display->coo.i++;
	}
	null_init_coo(&display->coo);
}

void	dis_null_init(t_display *display)
{
	display->mlx_id = NULL;
	display->win_id = NULL;
	display->bg = NULL;
	display->exit = NULL;
	display->exit_1 = NULL;
	display->item = NULL;
	display->player = NULL;
	display->player_1 = NULL;
	display->player_2 = NULL;
	display->wall = NULL;
	display->win_screen = NULL;
	null_init_coo(&display->coo);
	display->item_total = 0;
	display->item_counter = 0;
	display->move_counter = 1;
	display->anim = 0;
	display->sprite.h = 160;
	display->sprite.w = 160;
	display->window.h = (display->sprite.h * ft_matlen(display->map) + 160);
	display->window.w = (display->sprite.w * (ft_strlen(display->map[0]) - 1));
	count_collectibles(display);
}

void	null_init_coo(t_coor *coo)
{
	coo->i = 0;
	coo->j = 0;
}

void	init_coordinate(t_display *display)
{
	display->sprite_coo.i = display->sprite.w * display->coo.i + 160;
	display->sprite_coo.j = display->sprite.h * display->coo.j;
}

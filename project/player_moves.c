/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:18:08 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/02/08 14:44:35 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_display	*display)
{
	if (display->map[display->coo.i - 1][display->coo.j] != '1')
	{
		if (display->map[display->coo.i - 1][display->coo.j] == 'C')
			display->item_counter++;
		if (display->map[display->coo.i - 1][display->coo.j] == 'E' && \
		display->item_counter == display->item_total)
		{
			display->map[display->coo.i - 1][display->coo.j] = 'e';
			load_map(*display);
			open_exit(*display);
		}
		if (display->map[display->coo.i - 1][display->coo.j] != 'E')
		{
			display->move_counter++;
			display->map[display->coo.i - 1][display->coo.j] = 'P';
			display->map[display->coo.i][display->coo.j] = '0';
			load_map(*display);
			ft_printf("Total moves : %d\n", display->move_counter);
		}
	}
}

void	move_down(t_display	*display)
{
	if (display->map[display->coo.i + 1][display->coo.j] != '1')
	{
		if (display->map[display->coo.i + 1][display->coo.j] == 'C')
			display->item_counter++;
		if (display->map[display->coo.i + 1][display->coo.j] == 'E' && \
		display->item_counter == display->item_total)
		{
			display->map[display->coo.i + 1][display->coo.j] = 'e';
			load_map(*display);
			open_exit(*display);
		}
		if (display->map[display->coo.i + 1][display->coo.j] != 'E')
		{
			display->move_counter++;
			display->map[display->coo.i + 1][display->coo.j] = 'P';
			display->map[display->coo.i][display->coo.j] = '0';
			load_map(*display);
			ft_printf("Total moves : %d\n", display->move_counter);
		}
	}
}

void	move_right(t_display	*display)
{
	if (display->map[display->coo.i][display->coo.j + 1] != '1')
	{
		if (display->map[display->coo.i][display->coo.j + 1] == 'C')
			display->item_counter++;
		if (display->map[display->coo.i][display->coo.j + 1] == 'E' && \
		display->item_counter == display->item_total)
		{
			display->map[display->coo.i][display->coo.j + 1] = 'e';
			load_map(*display);
			open_exit(*display);
		}
		if (display->map[display->coo.i][display->coo.j + 1] != 'E')
		{
			display->move_counter++;
			display->map[display->coo.i][display->coo.j + 1] = 'P';
			display->map[display->coo.i][display->coo.j] = '0';
			load_map(*display);
			ft_printf("Total moves : %d\n", display->move_counter);
		}
	}
}

void	move_left(t_display	*display)
{
	if (display->map[display->coo.i][display->coo.j - 1] != '1')
	{
		if (display->map[display->coo.i][display->coo.j - 1] == 'C')
			display->item_counter++;
		if (display->map[display->coo.i][display->coo.j - 1] == 'E' && \
		display->item_counter == display->item_total)
		{
			display->map[display->coo.i][display->coo.j - 1] = 'e';
			load_map(*display);
			open_exit(*display);
		}
		else if (display->map[display->coo.i][display->coo.j - 1] != 'E')
		{
			display->move_counter++;
			display->map[display->coo.i][display->coo.j - 1] = 'P';
			display->map[display->coo.i][display->coo.j] = '0';
			load_map(*display);
			ft_printf("Total moves : %d\n", display->move_counter);
		}
	}
}

void	open_exit(t_display display)
{
	while (display.anim < 4000)
	{
		if (display.anim % 10 == 0)
		{
			display.map[display.coo.i][display.coo.j] = 'p';
			load_map(display);
		}
		else if (display.anim % 10 == 1)
		{
			display.map[display.coo.i][display.coo.j] = 'd';
			load_map(display);
		}
		display.anim++;
	}
	mlx_loop_end(display.mlx_id);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:18:08 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/02/16 11:15:12 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_display	*display)
{
	if (display->map[display->coo.i - 1][display->coo.j] != '1')
	{
		if (display->map[display->coo.i - 1][display->coo.j] == 'C')
			display->item_counter++;
		if (display->map[display->coo.i - 1][display->coo.j] != 'E')
		{
			display_move_counter(display);
			if (ft_printf("Total moves : %u\n", display->move_counter) == -1)
				mlx_error(*display, "ft_printf crashed :/\n");
			display->move_counter++;
			display->map[display->coo.i - 1][display->coo.j] = 'P';
			display->map[display->coo.i][display->coo.j] = '0';
			load_move(*display);
		}
		else if (display->map[display->coo.i - 1][display->coo.j] == 'E' && \
		display->item_counter == display->item_total)
		{
			display->map[display->coo.i - 1][display->coo.j] = 'e';
			open_exit(*display);
		}
		else
			if (ft_printf("%u items missing to unlock the exit !\n", \
			display->item_total - display->item_counter) == -1)
				mlx_error(*display, "ft_printf crashed :/\n");
	}
}

void	move_down(t_display	*display)
{
	if (display->map[display->coo.i + 1][display->coo.j] != '1')
	{
		if (display->map[display->coo.i + 1][display->coo.j] == 'C')
			display->item_counter++;
		if (display->map[display->coo.i + 1][display->coo.j] != 'E')
		{
			display_move_counter(display);
			if (ft_printf("Total moves : %u\n", display->move_counter) == -1)
				mlx_error(*display, "ft_printf crashed :/\n");
			display->move_counter++;
			display->map[display->coo.i + 1][display->coo.j] = 'P';
			display->map[display->coo.i][display->coo.j] = '0';
			load_move(*display);
		}
		else if (display->map[display->coo.i + 1][display->coo.j] == 'E' && \
		display->item_counter == display->item_total)
		{
			display->map[display->coo.i + 1][display->coo.j] = 'e';
			open_exit(*display);
		}
		else
			if (ft_printf("%u items missing to unlock the exit !\n", \
			display->item_total - display->item_counter) == -1)
				mlx_error(*display, "ft_printf crashed :/\n");
	}
}

void	move_right(t_display	*display)
{
	if (display->map[display->coo.i][display->coo.j + 1] != '1')
	{
		if (display->map[display->coo.i][display->coo.j + 1] == 'C')
			display->item_counter++;
		if (display->map[display->coo.i][display->coo.j + 1] != 'E')
		{
			display_move_counter(display);
			if (ft_printf("Total moves : %u\n", display->move_counter) == -1)
				mlx_error(*display, "ft_printf crashed :/\n");
			display->move_counter++;
			display->map[display->coo.i][display->coo.j + 1] = 'P';
			display->map[display->coo.i][display->coo.j] = '0';
			load_move(*display);
		}
		else if (display->map[display->coo.i][display->coo.j + 1] == 'E' && \
		display->item_counter == display->item_total)
		{
			display->map[display->coo.i][display->coo.j + 1] = 'e';
			open_exit(*display);
		}
		else
			if (ft_printf("%u items missing to unlock the exit !\n", \
			display->item_total - display->item_counter) == -1)
				mlx_error(*display, "ft_printf crashed :/\n");
	}
}

void	move_left(t_display	*display)
{
	if (display->map[display->coo.i][display->coo.j - 1] != '1')
	{
		if (display->map[display->coo.i][display->coo.j - 1] == 'C')
			display->item_counter++;
		if (display->map[display->coo.i][display->coo.j - 1] != 'E')
		{
			display_move_counter(display);
			if (ft_printf("Total moves : %u\n", display->move_counter) == -1)
				mlx_error(*display, "ft_printf crashed :/\n");
			display->move_counter++;
			display->map[display->coo.i][display->coo.j - 1] = 'P';
			display->map[display->coo.i][display->coo.j] = '0';
			load_move(*display);
		}
		else if (display->map[display->coo.i][display->coo.j - 1] == 'E' && \
		display->item_counter == display->item_total)
		{
			display->map[display->coo.i][display->coo.j - 1] = 'e';
			open_exit(*display);
		}
		else
			if (ft_printf("%u items missing to unlock the exit !\n", \
			display->item_total - display->item_counter) == -1)
				mlx_error(*display, "ft_printf crashed :/\n");
	}
}

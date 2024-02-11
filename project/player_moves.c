/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:18:08 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/02/09 18:05:34 by cdomet-d         ###   ########lyon.fr   */
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
			load_move(*display);
			open_exit(*display);
		}
		else if (display->map[display->coo.i - 1][display->coo.j] != 'E')
		{
			display->move_counter++;
			display->map[display->coo.i - 1][display->coo.j] = 'P';
			display->map[display->coo.i][display->coo.j] = '0';
			load_move(*display);
			ft_printf("Total moves : %u\n", display->move_counter);
		}
		else
			ft_printf("You are missing %u items to unlock the exit !\n", \
			display->item_total - display->item_counter);
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
			load_move(*display);
			open_exit(*display);
		}
		else if (display->map[display->coo.i + 1][display->coo.j] != 'E')
		{
			display->move_counter++;
			display->map[display->coo.i + 1][display->coo.j] = 'P';
			display->map[display->coo.i][display->coo.j] = '0';
			load_move(*display);
			ft_printf("Total moves : %u\n", display->move_counter);
		}
		else
			ft_printf("You are missing %u items to unlock the exit !\n", \
			display->item_total - display->item_counter);
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
			load_move(*display);
			open_exit(*display);
		}
		else if (display->map[display->coo.i][display->coo.j + 1] != 'E')
		{
			display->move_counter++;
			display->map[display->coo.i][display->coo.j + 1] = 'P';
			display->map[display->coo.i][display->coo.j] = '0';
			load_move(*display);
			ft_printf("Total moves : %u\n", display->move_counter);
		}
		else
			ft_printf("You are missing %u items to unlock the exit !\n", \
			display->item_total - display->item_counter);
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
			load_move(*display);
			open_exit(*display);
		}
		else if (display->map[display->coo.i][display->coo.j - 1] != 'E')
		{
			display->move_counter++;
			display->map[display->coo.i][display->coo.j - 1] = 'P';
			display->map[display->coo.i][display->coo.j] = '0';
			load_move(*display);
			ft_printf("Total moves : %u\n", display->move_counter);
		}
		else
			ft_printf("You are missing %u items to unlock the exit !\n", \
			display->item_total - display->item_counter);
	}
}

void	open_exit(t_display display)
{
	t_coor	center;
	char 	*str;

	errno = 0;
	str = ft_itoa(display.move_counter);
	if (errno)
		mem_err(display.map, 0, errno);
	while (display.anim < 60000)
	{
		if (display.anim % 2 == 0)
		{
			display.map[display.coo.i][display.coo.j] = 'p';
			player_anim(display);
		}
		else
		{
			display.map[display.coo.i][display.coo.j] = 'd';
			player_anim(display);
		}		
		display.anim++;
	}
	clear_map(&display);
	load_map(display);
	find_map_center(&display, &center);
	mlx_put_image_to_window(display.mlx_id, display.win_id, \
				display.win_screen, center.j * 160, center.i * 160);
	mlx_string_put(display.mlx_id, display.win_id, 480, 80, 16710368, "You won in");
	mlx_string_put(display.mlx_id, display.win_id, 560, 80, 16710368, str);
	free(str);
	mlx_string_put(display.mlx_id, display.win_id, 580, 80, 16710368, "moves !!");
	// mlx_loop_end(display.mlx_id);
}

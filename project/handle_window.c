/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:51:00 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/01/26 17:44:52 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x;
	int		y;

	x = 300;
	y = 500;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "Hello World!");
	while(1)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFC6C85);
		x++;
		y++;
		if (x >= 600)
			break ;
	}
	while(1)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFC6C85);
		x++;
		y--;
		if (y <= 500)
			break ;
	}
	sleep(20);
	mlx_clear_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:51:00 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/02/05 17:22:50 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_window(char **map)
{
	void 	*win_id;
	void	*mlx_id;
	void	*background;
	void	*wall;
	void	*collectibles;
	void	*player;
	int		width;
	int		height;
	size_t	win_width;
	size_t	win_height;
	size_t	i;
	size_t	j;

	printf("%ld\n", ft_strlen(map[0]));

	width = 160;
	height = 160;
	win_height = height * ft_matlen(map);
	win_width = width * (ft_strlen(map[0]) - 1);
	i = 0;
	j = 0;
	mlx_id = mlx_init();
	background = mlx_xpm_file_to_image(mlx_id, "../textures/bg.xpm", &width, &height);
	wall = mlx_xpm_file_to_image(mlx_id, "../textures/wall.xpm", &width, &height);
	collectibles = mlx_xpm_file_to_image(mlx_id, "../textures/items.xpm", &width, &height);
	player = mlx_xpm_file_to_image(mlx_id, "../textures/player.xpm", &width, &height);
	win_id = mlx_new_window(mlx_id, win_width, win_height, "so_long");
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(mlx_id, win_id, wall, height * j, width * i);
			else if (map[i][j] == 'C')
				mlx_put_image_to_window(mlx_id, win_id, collectibles, height * j, width * i);
			else if (map[i][j] == 'P')
				mlx_put_image_to_window(mlx_id, win_id, player, height * j, width * i);
			else
				mlx_put_image_to_window(mlx_id, win_id, background, height * j, width * i);
			j++;
		}
		i++;
	}
	sleep(60);
	mlx_destroy_image(mlx_id, background);
	mlx_destroy_image(mlx_id, wall);
	mlx_destroy_window(mlx_id, win_id);
	mlx_destroy_display(mlx_id);
	free(mlx_id);
}

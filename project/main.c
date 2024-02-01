/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:51:00 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/02/01 17:58:16 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	char	*map[MAX_ROW];
	t_coor	coor;
	size_t	count;

	coor.i = 0;
	coor.j = 0;
	count = 0;
	map[MAX_ROW - 1] = 0;
	if (argc == 1)
		init_map_stdin(map);
	else
		init_map_fd(map, argv[1]);
	is_map_valid(map);
	// coor = find_sprite_coordinates(map, 'E', coor);
	// printf("Exit coordinates = i - %ld || %ld - j\n", coor.i, coor.j);
	// coor.i = 0;
	// coor.j = 0;
	// coor = find_sprite_coordinates(map, 'C', coor);
	// is_item_trapped(map, coor.i, coor.j);
	print_map(map);
	// coor.i = 0;
	// coor.j = 0;
	coor = find_sprite_coordinates(map, 'P', coor);
	is_player_trapped(map, coor.i, coor.j);
	// printf("\n%d\n", is_sprite_trapped(map, &coor, coor));
	print_map(map);
	free_and_exit(map, errno);
}

		// printf("j + 1\n");
		// printf("coor || i - %ld || %ld - coor->j\n", coor->i, coor->j);
		// printf("prev || i - %ld || %ld - j\n", prev_step.i, prev_step.j);

		// printf("j - 1\n");
		// printf("coor || i - %ld || %ld - coor->j\n", coor->i, coor->j);
		// printf("prev || i - %ld || %ld - j\n", prev_step.i, prev_step.j);
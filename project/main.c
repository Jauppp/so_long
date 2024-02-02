/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:51:00 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/02/02 16:42:12 by cdomet-d         ###   ########lyon.fr   */
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
	print_map(map);
	is_map_valid(map);
	print_map(map);
	free_and_exit(map, errno);
}

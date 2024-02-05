/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:51:00 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/02/05 13:09:29 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	char	*map[MAX_ROW];
	t_coor	coor;

	coor.i = 0;
	coor.j = 0;
	map[MAX_ROW - 1] = 0;
	if (argc == 1)
		init_map_stdin(map);
	else if (argc == 2)
	{
		if (!map_extension_is_valid(argv[1]))
			parse_err(NULL, NULL, "Error\nInvalid map extension");	
		init_map_fd(map, argv[1]);
	}	
	else 
		parse_err(NULL, NULL, "Error\nToo many arguments");
	is_map_valid(map);
	open_window(map);
	free_and_exit(map, errno);
}

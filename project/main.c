/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:51:00 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/02/12 15:36:24 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	char		*map[MAX_ROW];
	t_display	display;

	map[MAX_ROW - 1] = 0;
	map[0] = NULL;
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
	display.map = copy_tab(map);
	free_tab(map);
	open_window(display);
	free_and_exit(display.map, 0);
}

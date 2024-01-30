/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:51:00 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/01/30 17:00:52 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	char	*map[MAX_ROW];

	(void)argv;
	map[MAX_ROW - 1] = 0;
	if (argc == 1)
		init_map_stdin(map);
	else
		init_map_fd(map, argv[1]);
	print_map(map);
	errno = 5;
	free_and_exit(map, errno);
}

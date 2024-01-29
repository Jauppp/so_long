/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:06:08 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/01/29 14:23:31 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    init_map_stdin(char **map)
{
    size_t  row;
    char    *new_row;

    new_row = NULL;
    row = 0;
    new_row = get_next_line(STDIN_FILENO);
    if (!new_row)
        free_and_exit(map, ERROR);
    while (new_row)
    {
        map[row] = new_row;
        row++;
        if (row == ROW_ERROR)
        {
            perror("Error in init_map_stdin: map is over 150 lines\n");
            map[ROW_ERROR] = 0;
            free_and_exit(map, ERROR);
        }
        new_row = get_next_line(STDIN_FILENO);
        // if (!new_row)
        // {
        //     map[row] = 0;
        //     free_and_exit(map, ERROR);
        // }
    }
    map[row] = 0;
}

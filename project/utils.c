/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:46:11 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/01/29 13:58:29 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_and_exit(char **map, int code)
{
    size_t  i;
    
    if ((!map || !*map) && code == SUCCESS)
        exit(STDOUT_FILENO);
    else if ((!map || !*map) && code == ERROR)
        exit(STDERR_FILENO);
    i = 0;
    while (map[i])
        free(map[i++]);
    if (code == SUCCESS)
        exit(STDOUT_FILENO);
    else if (code == ERROR)
        exit(STDERR_FILENO);
}
void print_map(char **map)
{
    size_t  i;
    if (!map && !*map)
        return ;
    i = 0;
    ft_printf("|===== [PRINT] =====|\n");
    while (map[i])
    {
        ft_printf("row = %s", map[i]);
        i++;
    }
    ft_printf("|===================|\n");
}
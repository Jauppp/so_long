/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:46:11 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/01/30 16:31:50 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_and_exit(char **map, int error_code)
{
	size_t	i;

	if (!map || !*map)
		exit(STDOUT_FILENO);
	i = 0;
	while (map[i])
		free(map[i++]);
	if (!error_code)
		exit(EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);
}


void	error_exit(char **map, size_t row, int error_code)
{
	map[row] = 0;
	printf("Error : %s", strerror(error_code));
	free_and_exit(map, error_code);
}

void	print_map(char **map)
{
	size_t	i;

	if (!map && !*map)
		return ;
	i = 0;
	ft_printf("|===== [PRINT] =====|\n");
	while (map[i])
	{
		ft_printf("%s", map[i]);
		i++;
	}
	ft_printf("|===================|\n");
}

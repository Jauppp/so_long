/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:15:28 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/02/02 17:10:44 by cdomet-d         ###   ########lyon.fr   */
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
void	free_double_tab(char **double_tab)
{
	size_t	i;

	i = 0;
	if (!double_tab || !*double_tab)
		return ;
	while (double_tab[i])
		free(double_tab[i++]);
	free(double_tab);
	double_tab = NULL;
	return ;
}

void	mem_err(char **map, size_t row, int error_code)
{
	if (row)
		map[row] = 0;
	ft_printf("Error : %s\n", strerror(error_code));
	free_and_exit(map, error_code);
}

void	parse_err(char **map, char **map_cpy, char *error_message)
{
	if (error_message)
		ft_printf("%s\n", error_message);
	if (map_cpy)
		free_double_tab(map_cpy);
	free_and_exit(map, ERR);
}

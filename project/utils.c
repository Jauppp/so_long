/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:46:11 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/02/12 13:32:01 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_matlen(char **str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i][0] != '\n')
		i++;
	return (i);
}

size_t	ft_strlen_n(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

void	clear_map(t_display *display)
{
	size_t	len;
	size_t	matlen;

	matlen = ft_matlen(display->map) - 1;
	len = ft_strlen_n(display->map[0]) - 1;
	display->coo.i = 1;
	while (display->coo.i < matlen)
	{
		display->coo.j = 1;
		while (display->coo.j < len)
			display->map[display->coo.i][display->coo.j++] = '0';
		display->coo.i++;
	}
}

void	find_map_center(t_display *display, t_coor *center)
{
	t_coor	low_right_corner;

	low_right_corner.i = ft_matlen(display->map) - 1;
	low_right_corner.j = ft_strlen_n(display->map[0]) - 1;
	center->i = (low_right_corner.i / 2) + 1;
	center->j = low_right_corner.j / 2;
	display->coo.i = center->i;
	display->coo.j = center->j;
	display->map[display->coo.i][display->coo.j] = 'P';
}

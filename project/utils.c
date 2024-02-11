/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:46:11 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/02/08 14:34:52 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(char **map)
{
	size_t	i;

	if (!map && !*map)
		return ;
	i = 0;
	ft_printf("\n|============= [MAP] ==============|\n\n");
	while (map[i])
	{
		ft_printf(" ");
		ft_printf("%s", map[i++]);
	}
	ft_printf("\n|==================================|\n");
}

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
	while (str[i] && 	str[i] != '\n')
		i++;
	return (i);
}

void	count_collectibles(t_display *display)
{
	while (display->map[display->coo.i])
	{
		display->coo.j = 0;
		while (display->map[display->coo.i][display->coo.j])
		{
			if (display->map[display->coo.i][display->coo.j] == 'C')
				display->item_total++;
			display->coo.j++;
		}
		display->coo.i++;
	}
	null_init_coo(&display->coo);
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
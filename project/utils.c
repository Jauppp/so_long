/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:46:11 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/02/07 16:51:46 by cdomet-d         ###   ########lyon.fr   */
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

void	dis_null_init(t_display *display)
{
	display->mlx_id = NULL;
	display->win_id = NULL;
	display->bg = NULL;
	display->exit = NULL;
	display->item = NULL;
	display->player = NULL;
	display->wall = NULL;
	display->coo.i = 0;
	display->coo.j = 0;
	display->sprite_coo.i = 0;
	display->sprite_coo.j = 0;
	display->sprite.h = 160;
	display->sprite.w = 160;
	display->window.h = display->sprite.h * ft_matlen(display->map);
	display->window.w = display->sprite.w * (ft_strlen(display->map[0]) - 1);
}

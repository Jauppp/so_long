/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:02:55 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/02/05 13:09:41 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <errno.h>
# include "../build/libft/libft.h"
# include "../build/mlx/mlx.h"
# include "../build/mlx/mlx_int.h"

# define MAX_ROW 150
# define SUCCESS 1
# define FAILURE 0
# define ERR 2

typedef struct s_struct
{
	size_t	i;
	size_t	j;
}	t_coor;

/* Utils */
size_t	ft_matlen(char **str);
void	print_map(char **map);

/* Map handling */
char	**copy_tab(char **map);
void	init_map_fd(char **map, char *arg);
void	init_map_stdin(char **map);
void	is_map_valid(char **map);

/* Parsing */
int		map_has_collectible(char **map);
int		map_has_one_exit(char **map);
void	map_has_one_start_position(char **map);
void	map_is_closed(char **map);
void	map_is_rectangular(char **map);

/* Parsing utils*/
int		check_row_is_wall(char *map);
int		map_extension_is_valid(char *str);
size_t	count_collectibles(char **map);
t_coor	find_sprite_coordinates(char **map, char sprite, t_coor coordinates);
void	is_sprite_trapped(char **map, size_t i, size_t j);


/* Error handling */
void	free_and_exit(char **map, int error_code);
void	free_double_tab(char **double_tab);
void	mem_err(char **map, size_t row, int error_code);
void	parse_err(char **map, char **map_cpy, char *error_message);

/* Window handling */
void	open_window(char **map);

#endif
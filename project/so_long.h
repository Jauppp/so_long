/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:02:55 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/02/06 16:21:25 by cdomet-d         ###   ########lyon.fr   */
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

typedef struct s_coor
{
	size_t	i;
	size_t	j;
}	t_coor;

typedef struct s_size
{
	int	w;
	int	h;
}	t_size;

typedef struct s_display
{
	void		*win_id;
	void		*mlx_id;
	void		*bg;
	void		*wall;
	void		*item;
	void		*player;
	void		*exit;
	t_size		sprite;
	t_size		window;
	t_coor		coo;
}	t_display;

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
void	free_mlx(t_display display);
void	mem_err(char **map, size_t row, int error_code);
void	parse_err(char **map, char **map_cpy, char *error_message);

/* Window handling */
void	open_window(char **map);

/* Init display */
void	init_display(t_display *display, char **map);
void	init_sprites(t_display *display);
void	init_coordinate(t_coor *img, t_display display);
void	load_map(t_display display, t_coor img, char **map);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:02:55 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/02/09 17:51:31 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <errno.h>
# include "../build/libft/libft.h"
# include "../build/mlx/mlx.h"
# include "../build/mlx/mlx_int.h"

# define MAX_ROW 50
# define SUCCESS 1
# define FAILURE 0
# define ERR 2
# define ESC 65307
# define DESTROY -16779216

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
	char				**map;
	size_t				anim;
	t_coor				coo; // x & y indexes to navigate in map
	t_coor				sprite_coo; // x & y placement of sprites in window
	t_size				sprite; // sprites height & width
	t_size				window; // window size for dynamic sizing
	unsigned int		item_counter;
	unsigned int		item_total;
	unsigned int		move_counter;
	void				*bg;
	void				*exit_1;
	void				*exit;
	void				*item;
	void				*mlx_id;
	void				*player_1;
	void				*player_2;
	void				*player;
	void				*wall;
	void				*win_id;
}	t_display;

/* Utils */
size_t	ft_matlen(char **str);
void	print_map(char **map);
void	dis_null_init(t_display *display);
void	count_collectibles(t_display *display);
void	null_init_coo(t_coor *coo);

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
t_coor	find_sprite_coordinates(char **map, char sprite, t_coor coordinates);
void	is_sprite_trapped(char **map, size_t i, size_t j);
void	char_is_valid(char **map);

/* Error handling */
void	mem_err(char **map, size_t row, int error_code);
void	parse_err(char **map, char **map_cpy, char *error_message);
void	mlx_error(t_display display, char *error_message);
void	print_error(int error_code, char *error_message);


/* Window handling */
void	open_window(t_display display);

/* Init display */
void	init_display(t_display *display);
void	init_decor(t_display *display);
void	init_player(t_display *display);
void	init_coordinate(t_display *display);
void	load_map(t_display display);
void	load_decor(t_display display);
void	load_player(t_display display);
void	load_move(t_display	display);
void	player_anim(t_display display);


/* Memory handling*/
void	free_and_exit(char **map, int error_code);
void	free_double_tab(char **double_tab);
void	free_mlx(t_display display);
void	free_tab(char **map);

/* Hook functions */
int		key_hook(int keycode, t_display *display);
int		mouse_hook(int button, int x, int y, t_display *display);
int		close_win(t_display *display);
void	clear_player_move(t_display *display);
void	display_player_move(t_display *display);

/* Player moves */
void	move_up(t_display	*display);
void	move_down(t_display	*display);
void	move_right(t_display	*display);
void	move_left(t_display	*display);
void	open_exit(t_display display);


#endif
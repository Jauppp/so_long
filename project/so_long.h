/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:02:55 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/01/30 17:03:51 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <errno.h>
# include "../build/libft/libft.h"
# include "../build/mlx/mlx.h"
# include "../build/mlx/mlx_int.h"

# define MAX_ROW 16
# define ROW_ERROR 15
# define SUCCESS 1
# define ERROR 0

/* Utils */
void	error_exit(char **map, size_t row, int error_code);
void	free_and_exit(char **map, int error_code);
void	print_map(char **map);

/* Map handling */
void	init_map_stdin(char **map);
void	init_map_fd(char **map, char *arg);

#endif
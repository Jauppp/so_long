/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:02:55 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/01/29 14:18:57 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../build/libft/libft.h"
# include "../build/mlx/mlx.h"
# include "../build/mlx/mlx_int.h"

# define MAX_ROW 16
# define ROW_ERROR 15
# define SUCCESS 1
# define ERROR 0

/* Utils */
void    free_and_exit(char **map, int code);
void    print_map(char **map);

/* Map handling */
void    init_map_stdin(char **map);

#endif
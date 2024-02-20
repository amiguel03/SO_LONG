/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:02:57 by amiguel-          #+#    #+#             */
/*   Updated: 2024/02/20 12:21:58 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
// # include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "structs.h"

/* ****** Defino las keycode ****** */

# define A 0
# define S 1
# define D 2
# define W 13
# define LEFT 123
# define DOWN 125
# define RIGTH 124
# define UP 126
# define ESC 53

# define PLYR_SPT	0
# define COLL_SPT	1
# define BACK_SPT	2
# define WALL_SPT	3
# define OUTD_SPT	4
# define MAP_CH		"01CEPM"

# define ARGUMENTS_ERROR_MSG	"Error de argumentos!\n"
# define ERROR_INIT_MSG			"Error creando la info del juego!\n"

/* ****** Defino funciones ****** */
t_map		*get_map(char *filename);
void		*delete_map(t_map *map);
t_map		*check_map(t_map *map);
int			set_points(t_map *map);
int			count_consum(t_map *map);
int			detect_path(t_map *map);
int			map_locked(t_map *map);

#endif

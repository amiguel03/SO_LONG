/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:02:57 by amiguel-          #+#    #+#             */
/*   Updated: 2024/02/26 17:41:35 by amiguel-         ###   ########.fr       */
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

# define IMAGE_HEIGHT 144
# define IMAGE_WEIGHT 144

# define ARGUMENTS_ERROR_MSG	"Error de argumentos!\n"
# define ERROR_INIT_MSG			"Error creando la info del juego!\n"

# define PLAYER1		"textures/player/.xpm"
# define PLYER2		"textures/player/.xpm"
# define PLY_DN			"textures/player/.xpm"
# define PLY_UP			"textures/player/.xpm"
# define PLY_LF			"textures/player/.xpm"
# define PLY_RG			"textures/player/.xpm"
# define WALL1	"textures/wall/.xpm"
# define WALL2	"textures/wall/.xpm"
# define BACK1	"textures/background/.xpm"
# define BACK2	"textures/background/.xpm"
# define DOOR_CLOSE		"textures/door/.xpm"
# define COLL1			"textures/collec/.xpm"
# define COLL2			"textures/collec/.xpm"

/* ****** Funciones ****** */
t_map		*get_map(char *filename);
void		*delete_map(t_map *map);
t_map		*check_map(t_map *map);
int			set_points(t_map *map);
int			count_consum(t_map *map);
int			detect_path(t_map *map);
int			map_locked(t_map *map);
int			render(t_win *win);
int			end_game(t_win *win);
int			key_hook(int key, t_win *win);
static int	set_sprites(t_win win);
t_win		*get_win(int columns, int rows);
static void	set_sprite_pos(t_game *game, int pos);
void		move_right(t_game *game);
void		move_left(t_game *game);
void		move_down(t_game *game);
void		move_up(t_game *game);
static void	print_player(t_win *win, int frame);
void		change_sprites(t_win *win, int frame);
void		*delete_player(t_player *player);
t_player	*get_player(t_map *map);
static int	push_player(t_win *win);
static int	push_wall(t_win *win);
static int	push_back(t_win *win);
static int	push_coll(t_win *win);
int			push_images(t_win *win);
static void	print_sprites(t_win *win, int w, int h, void *sprite);
void		manage_sprites(t_win *win, int x, int y);
void		*delete_game(t_game *game);
t_game		*get_game(char *filename);
void		print_steps(t_game *game);
void		print_end(t_game *game);

#endif

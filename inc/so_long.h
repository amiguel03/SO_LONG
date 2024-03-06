/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:22:25 by amiguel-          #+#    #+#             */
/*   Updated: 2024/03/06 17:22:54 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include "structs.h"

# define BUFFER_SIZE 1000000
# define FLOOR "textures/back.xpm"
# define WALL "textures/wall.xpm"
# define COIN "textures/coll.xpm"
# define PLAYER "textures/player.xpm"
# define EXIT_CLOSE "textures/door.xpm"
# define SPRITE_SIZE 144

int		count_objs(char **map, int c);
void	check_objs(char **map);
void	ft_error(char *str);
char	**flood_map(int row, int col, char **map);
char	**flooder_player(t_game *game, char **map);
void	init_map(t_window *window, char **map);
void	init_mlx(t_window *window, char **new_map);
void	move_up(t_window *window);
void	move_right(t_window *window);
void	move_down(t_window *window);
void	move_left(t_window *window);
int		open_map(char *str);
void	setmap(int fd, t_game *game);
void	print_sprites(t_window *window, char **map);
void	putnbr(int n);
char	**split(const char *s, char c);
int		strlen_row(char **map);
int		strlen_col(const char *str);
char	*substr(const char *s, unsigned int start, size_t len);
int		close_window(t_window *window);
int		key_hook(int keycode, t_window *window);
int		verify_extension(const char *str);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:02:57 by amiguel-          #+#    #+#             */
/*   Updated: 2024/02/14 15:39:24 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
// # include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

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

# define ARGUMENTS_ERROR_MSG	"Error de argumentos!\n"
# define ERROR_INIT_MSG			"Error creando la info del juego!\n"

/* ****** Defino las distintas estructuras ****** */

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_point
{
	int x;//coordenada x
	int y;//coodenada y
}				t_point;

typedef struct 	s_map {
	char	**matrix;//mapa guardado en matriz
	int		row;//fila
	int		column;//columna
	int		nconsum;//numero de cconsummibles
	t_point in;//coordenadas de entrada
	t_point out;//coordenadas de salida
}				t_map;

typedef struct	s_character {
	t_point coords;//coordenadas del personaje
	int		ncolect;//numero de consumibles que lleva
}				t_character;

typedef struct	s_win {
 	void	*mlx;//minilibx
	void	*win;//ventana que abrimos
	void	**sprites;//sprites que abrimos
}				t_win;

typedef struct	s_controler {
 	t_win		*window;
	t_map		*map;
	t_character	*player;
}				t_controler;

t_controler *init_data(char *map_name);

#endif
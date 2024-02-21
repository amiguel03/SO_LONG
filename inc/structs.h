/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:56:33 by amiguel-          #+#    #+#             */
/*   Updated: 2024/02/20 15:27:00 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/* ****** Defino las distintas estructuras ****** */

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

typedef struct	s_player {
	t_point coords;//coordenadas del personaje
	int		ncolect;//numero de consumibles que lleva
}				t_player;

typedef struct	s_win {
 	void		*mlx;//minilibx
	void		*win;//ventana que abrimos
	char		**map;//mapa que abrimos
	void		**sprites;//sprites que abrimos
	void		*player_sprite;//sprites del jugador
	void		*wall_sprite;//sprites del muro
	void		*floor_sprite;//sprites del suelo
	void		*end_sprite;//sprite del final
	void		*cons_sprite;//sprite del consumible
	t_game		*game;
	int			count;
	int			frame;
	t_images	*sprites;
	int			ply_priority;
	int			ply_frame;
}				t_win;

typedef struct	s_game {
 	t_win		*window;
	t_map		*map;
	t_player	*player;
	int			steps;
}				t_game;

typedef struct s_images {
	void 		*player;
	void		*player_up;
	void		*player_down;
	void		*player_right;
	void		*player_left;
	void		*wall;
	void		*back;
	void		*cons;	
} 				t_images;

#endif
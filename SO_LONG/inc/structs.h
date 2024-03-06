/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:22:23 by amiguel-          #+#    #+#             */
/*   Updated: 2024/03/06 16:04:03 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/* ****** Defino las distintas estructuras ****** */

typedef struct s_game	t_game;
typedef struct s_window	t_window;

struct s_window {
	void	*mlx;
	void	*win;
	t_game	*game;
};

struct s_game
{
	int		x_player;
	int		y_player;
	char	**map;
	int		coin;
	int		steps;
	char	**map_copy;
};

#endif
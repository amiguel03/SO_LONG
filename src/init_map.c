/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:42:37 by amiguel-          #+#    #+#             */
/*   Updated: 2024/03/06 16:08:47 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	verify_rectangle(char **map)
{
	int	row;
	int	len;

	row = 0;
	len = strlen_col(map[0]);
	while (map[row] != NULL)
	{
		if (len != strlen_col(map[row]))
			ft_error("Error.\nMapa invallido.\n");
		row++;
	}
}

static void	verify_wall(char **map)
{
	int	row;
	int	col;

	row = 0;
	while (map[row] != NULL)
	{
		col = 0;
		while (map[row][col] != '\0')
		{
			if (map[0][col] != '1' || map[strlen_row(map) - 1][col] != '1')
				ft_error("Error\n.Mapa invalido.\n");
			if (map[row][0] != '1' || map[row][strlen_col(map[row]) - 1] != '1')
				ft_error("Error\n.Mapa invalido.\n");
			col++;
		}
		row++;
	}
}

static void	verify_objects(char **map, t_window *window)
{
	int		c;
	int		e;
	int		p;

	check_objs(map);
	c = count_objs(map, 'C');
	window->game->coin = c;
	e = count_objs(map, 'E');
	p = count_objs(map, 'P');
	if (c < 1)
		ft_error("Error\n.Mapa invalido.\n");
	if (e != 1)
		ft_error("Error\n.Mapa invalido.\n");
	if (p != 1)
		ft_error("Error\n.Mapa invalido.\n");
}

static void	verify_path(t_game *game, char **map)
{
	char	**map_flooded;
	int		c;
	int		e;

	map_flooded = flooder_player(game, map);
	c = count_objs(map_flooded, 'C');
	if (c != 0)
		ft_error("Error\n.Mapa invalido.\n");
	e = count_objs(map_flooded, 'E');
	if (e != 0)
		ft_error("Error\n.Mapa invalido.\n");
}

void	init_map(t_window *window, char **map)
{
	verify_rectangle(map);
	verify_wall(map);
	verify_objects(map, window);
	verify_path(window->game, map);
}

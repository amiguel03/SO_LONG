/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:56:28 by amiguel-          #+#    #+#             */
/*   Updated: 2024/03/06 15:47:16 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	**flood_map(int row, int col, char **map)
{
	if (map[row][col] == 'E')
	{
		map[row][col] = '1';
		return (map);
	}
	map[row][col] = '1';
	if (map[row - 1][col] != '1')
		flood_map(row - 1, col, map);
	if (map[row][col + 1] != '1')
		flood_map(row, col + 1, map);
	if (map[row + 1][col] != '1')
		flood_map(row + 1, col, map);
	if (map[row][col - 1] != '1')
		flood_map(row, col - 1, map);
	return (map);
}

char	**flooder_player(t_game *game, char **map)
{
	int		row;
	int		col;
	char	**map_flooded;

	row = 0;
	while (map[row] != NULL)
	{
		col = 0;
		while (map[row][col] != '\0')
		{
			if (map[row][col] == 'P')
			{
				game->x_player = col;
				game->y_player = row;
				map_flooded = flood_map(row, col, map);
			}
			col++;
		}
		row++;
	}
	return (map_flooded);
}

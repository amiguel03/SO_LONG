/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:03:10 by amiguel-          #+#    #+#             */
/*   Updated: 2024/02/26 17:38:01 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	detect_path_rec(char **map, int x, int y, t_map *data)
{
	int	count;
	int	x_max;
	int	y_max;

	x_max = data->column;
	y_max = data->row;
	count = 0;
	if (map[y][x] == 'E')
		return (1);
	else
		map[y][x] = 1;
	if (x - 1 >= 0 && map[y][x - 1] != '1' && map[y][x - 1] != 'M')
		count += detect_path_rec(map, x - 1, y, data);
	if (x + 1 < x_max && map[y][x + 1] != '1' && map[y][x + 1] != 'M')
		count += detect_path_rec(map, x + 1, y, data);
	if (y - 1 >= 0 && map[y - 1][x] != '1' && map[y - 1][x] != 'M')
		count += detect_path_rec(map, x, y - 1, data);
	if (y + 1 < y && map[y + 1][x] != '1' && map[y + 1][x] != 'M')
		count += detect_path_rec(map, x, y + 1, data);
	return (count);
}

static void	check_collect(int *res, char **map)
{
	int	x;
	int	y;

	y = 0;
	if (*res == 0)
		return ;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
			{
				*res = 0;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	detect_path(t_map *map)
{
	char	**map_copy;
	int		y;
	int		res;

	y = 0;
	map_copy = (char **)malloc((map->row +1) * sizeof(char *));
	if (!map_copy)
		return (0);
	while (map->matrix[y])
	{
		map_copy[y] = ft_strdup(map->matrix[y]);
		y++;
	}
	map_copy[y] = NULL;
	res = detect_path_rec(map_copy, map->in.x, map->in.y, map);
	check_collect(&res, map_copy);
	y = 0;
	while (map_copy[y])
		free (map_copy[y++]);
	free (map_copy);
	return (res);
}

int	map_locked(t_map *map)
{
	int		x;
	int		y;

	y = 0;
	while (map->matrix[y])
	{
		x = 0;
		while (map->matrix[y][x])
		{
			if ((y == 0 || y == map->row - 1) && map->matrix[y][x] != '1')
				return (0);
			if (x == 0 && map->matrix[y][x] != '1')
				return (0);
			x++;
		}
		if (map->matrix[y][x -1] != 1)
			return (0);
		y++;
	}
	return (1);
}

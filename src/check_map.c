/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:12:45 by amiguel-          #+#    #+#             */
/*   Updated: 2024/02/26 12:06:47 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	count_consum(t_map *map)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	if (!(map->matrix))
		return (-1);
	while (map->matrix[y])
	{
		x = 0;
		while (map->matrix[y][x])
		{
			if (map->matrix[y][x])
				count++;
			if (!ft_strchr(MAP_CH, map->matrix[y][x]))
				return (-1);
			x++;
		}
		y++;
	}
	return (count);
}

static int	set_in(t_map *map, int *start, int x, int y)
{
	if (start != 0)
		return (1);
	map->in.x = x;
	map->in.x = y;
	*start = 1;
	return (0);
}

static int	set_out(t_map *map, int *end, int x, int y)
{
	if (end != 0)
		return (1);
	map->out.x = x;
	map->out.x = y;
	*end = 1;
	return (0);
}

int	set_points(t_map *map)
{
	int	x;
	int	y;
	int	start;
	int	end;

	start = 0;
	end = 0;
	y = -1;
	if (!(map->matrix))
		return (-1);
	while (map->matrix[++y])
	{
		x = 0;
		while (map->matrix[y][x])
		{
			if (map->matrix[y][x] == 'P')
				if (set_in(map, &start, x, y))
					return (1);
			if (map->matrix[y][x] == 'E')
				if (set_out(map, &end, x, y))
					return (1);
			x++;
		}
	}
	return (0);
}

t_map	*check_map(t_map *map)
{
	if (!map)
		return (NULL);
	if (map->row < 1 || map->column < 1 || !(map->matrix))
		return (delete_map(map));
	if (map->nconsum < 1 || set_points(map))
		return (delete_map(map));
	if (!map_locked(map) || !detect_path(map))
		return (delete_map(map));
	return (map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:19:07 by amiguel-          #+#    #+#             */
/*   Updated: 2024/03/05 11:58:13 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	get_row(char *filename)
{
	int		fd;
	int		row;
	char	*line;

	row = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		row++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return (row);
}

static int	get_column(char **map)
{
	int		j;
	int		i;
	int		length;

	i = 0;
	length = 0;
	if (!map)
		return (-1);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (length == 0)
			length = j;
		else
		{
			if (length != j)
				return (-1);
		}
		i++;
	}
	if (j < 0)
		exit (EXIT_FAILURE);
	return (j);
}

static char	**read_map(char *filename)
{
	int		fd;
	int		rows;
	int		i;
	char	**map;

	i = 0;
	rows = get_row(filename);
	if (rows == -1)
		return (NULL);
	map = (char **)malloc((rows + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	fd = open(filename, O_RDONLY);
	while (i < rows)
	{
		map[i] = get_next_line(fd);
		if (i != rows - 1)
			map[i][ft_strlen(map[i]) - 1] = '\0';
		i++;
	}
	map[i] = NULL;
	return (map);
}

t_map	*get_map(char *filename)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->row = get_row(filename);
	map->matrix = read_map(filename);
	map->column = get_column(map->matrix);
	return (map);
}

void	*delete_map(t_map *map)
{
	int		i;

	i = 0;
	if (!map)
		return (NULL);
	if (map->matrix)
	{
		while (map->matrix[i])
			free(map->matrix[i++]);
		free(map->matrix);
	}
	free(map);
	return (NULL);
}

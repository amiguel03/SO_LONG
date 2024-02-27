/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:19:07 by amiguel-          #+#    #+#             */
/*   Updated: 2024/02/27 15:30:32 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"







void	prueba(char *filename, t_game *game)
{
	int		fd;
	int column;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	line = get_next_line(fd);
	printf("Buenas %s\n", line);
	column = ft_strlen(line);
	printf("Columna %d\n", column);
	free(line);
	game->map->row = 1;
	printf("Buenas\n");
	while (line)
	{
		free(line);
		game->map->row++;
		line = get_next_line(fd);
	}
	printf("Row: %d\n", game->map->row);
	printf("Column: %d\n", game->map->column);
	close(fd);
}


























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
	while (line)
	{
		free(line);
		row++;
		line = get_next_line(fd);
	}
	close(fd);
	return (row);
}

static int	get_column(char **map)
{
	int		column;
	int		j;
	int		i;

	i = 0;
	column = -1;
	if (!map)
		return (-1);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (column == -1)
			column = i;
		if (column != j)
			return (-1);
		i++;
	}
	return (column);
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
	map->column = get_column(map->matrix);
	map->matrix = read_map(filename);
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

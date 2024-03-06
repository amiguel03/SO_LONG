/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:05:16 by amiguel-          #+#    #+#             */
/*   Updated: 2024/03/06 15:43:59 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	open_map(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		ft_error("Error\n.Error en la apertura de el archivo.\n");
	return (fd);
}

void	setmap(int fd, t_game *game)
{
	char	*line_map;
	ssize_t	map_len;
	char	**map;
	char	**map_copy;

	line_map = (char *)malloc(BUFFER_SIZE * sizeof(char));
	map_len = read(fd, line_map, BUFFER_SIZE);
	line_map[map_len] = '\0';
	map = split(line_map, '\n');
	map_copy = split(line_map, '\n');
	if (map == NULL || map_copy == NULL)
		ft_error("Error\n.No es posible hacer el split.\n");
	game->map = map;
	game->map_copy = map_copy;
	free(line_map);
	line_map = NULL;
}

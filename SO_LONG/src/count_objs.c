/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_objs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:55:03 by amiguel-          #+#    #+#             */
/*   Updated: 2024/03/06 16:13:15 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	count_objs(char **map, int c)
{
	int	row;
	int	col;
	int	count;

	row = 0;
	count = 0;
	while (map[row] != NULL)
	{
		col = 0;
		while (map[row][col] != '\0')
		{
			if (map[row][col] == c)
				count++;
			col++;
		}
		row++;
	}
	return (count);
}

void	check_objs(char **map)
{
	int	row;
	int	col;

	row = 0;
	while (map[row] != NULL)
	{
		col = 0;
		while (map[row][col] != '\0')
		{
			if ((map[row][col] != '1') && (map[row][col] != '0') &&
				(map[row][col] != 'P') && (map[row][col] != 'E') &&
				(map[row][col] != 'C'))
				ft_error("Error.\nMapa invalido.\n");
			col++;
		}
		row++;
	}
}

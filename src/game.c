/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:24:54 by amiguel-          #+#    #+#             */
/*   Updated: 2024/02/27 15:31:30 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	*delete_game(t_game *game)
{
	if (!game)
		return (NULL);
	if (game->map)
		delete_map(game->map);
	if (game->player)
		delete_player(game->player);
	free(game);
	return (NULL);
}

t_game	*get_game(char *filename)
{
	t_game	*game;

	if (!filename)
		return (NULL);
	game = (t_game *)malloc(sizeof(t_game) * 1);
	if (!game)
		return (NULL);
	game->map = get_map(filename, game);
	if (!(game->map))
	{
		write(1, "Error. Error reading the map\n", 30);
		return (free(game), NULL);
	}
	game->player = get_player(game->map);
	if (!game->player)
		return (delete_game(game));
	game->win = get_win(game->map->column, game->map->row);
	if (!game->win)
		return (delete_game(game));
	game->win->map = game->map->matrix;
	game->win->game = game;
	game->steps = 0;
	return (game);
}

void	print_steps(t_game *game)
{
	write(1, "Steps: ", 7);
	ft_putnbr_fd(game->steps, 1);
	write(1, "\n", 1);
}

void	print_end(t_game *game)
{
	write(1, "\n\t\t\t\t  ", 7);
	print_steps(game);
	write(1, "\n", 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:33:32 by amiguel-          #+#    #+#             */
/*   Updated: 2024/03/06 15:44:16 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	move_up(t_window *window)
{
	int	x;
	int	y;

	x = window->game->x_player;
	y = window->game->y_player;
	if ((window->game->map[y - 1][x] != '1') &&
		(window->game->map[y - 1][x] != 'E'))
	{
		if (window->game->map[y - 1][x] == 'C')
			window->game->coin--;
		window->game->steps++;
		putnbr(window->game->steps);
		write(1, "\n", 1);
		window->game->map[y][x] = '0';
		window->game->map[y - 1][x] = 'P';
		mlx_clear_window(window->mlx, window->win);
		print_sprites(window, window->game->map);
		window->game->y_player = y - 1;
	}
	else if ((window->game->map[y - 1][x] == 'E') &&
		(window->game->coin == 0))
		close_window(window);
}

void	move_right(t_window *window)
{
	int	x;
	int	y;

	x = window->game->x_player;
	y = window->game->y_player;
	if ((window->game->map[y][x + 1] != '1') &&
		(window->game->map[y][x + 1] != 'E'))
	{
		if (window->game->map[y][x + 1] == 'C')
			window->game->coin--;
		window->game->steps++;
		putnbr(window->game->steps);
		write(1, "\n", 1);
		window->game->map[y][x] = '0';
		window->game->map[y][x + 1] = 'P';
		mlx_clear_window(window->mlx, window->win);
		print_sprites(window, window->game->map);
		window->game->x_player = x + 1;
	}
	else if ((window->game->map[y][x + 1] == 'E') &&
		(window->game->coin == 0))
		close_window(window);
}

void	move_down(t_window *window)
{
	int	x;
	int	y;

	x = window->game->x_player;
	y = window->game->y_player;
	if ((window->game->map[y + 1][x] != '1') &&
		(window->game->map[y + 1][x] != 'E'))
	{
		if (window->game->map[y + 1][x] == 'C')
			window->game->coin--;
		window->game->steps++;
		putnbr(window->game->steps);
		write(1, "\n", 1);
		window->game->map[y][x] = '0';
		window->game->map[y + 1][x] = 'P';
		mlx_clear_window(window->mlx, window->win);
		print_sprites(window, window->game->map);
		window->game->y_player = y + 1;
	}
	else if ((window->game->map[y + 1][x] == 'E') &&
		(window->game->coin == 0))
		close_window(window);
}

void	move_left(t_window *window)
{
	int	x;
	int	y;

	x = window->game->x_player;
	y = window->game->y_player;
	if ((window->game->map[y][x - 1] != '1') &&
		(window->game->map[y][x - 1] != 'E'))
	{
		if (window->game->map[y][x - 1] == 'C')
			window->game->coin--;
		window->game->steps++;
		putnbr(window->game->steps);
		write(1, "\n", 1);
		window->game->map[y][x] = '0';
		window->game->map[y][x - 1] = 'P';
		mlx_clear_window(window->mlx, window->win);
		print_sprites(window, window->game->map);
		window->game->x_player = x - 1;
	}
	else if ((window->game->map[y][x - 1] == 'E') &&
		(window->game->coin == 0))
		close_window(window);
}

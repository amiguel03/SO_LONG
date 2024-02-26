/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:14:04 by amiguel-          #+#    #+#             */
/*   Updated: 2024/02/26 17:48:49 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	set_sprite_pos(t_game *game, int pos)
{
	t_images	*sprites;

	sprites = game->win->sprites;
	if (pos == 0)
		game->win->player_sprite = sprites->player_up;
	else if (pos == 1)
		game->win->player_sprite = sprites->player_right;
	else if (pos == 2)
		game->win->player_sprite = sprites->player_left;
	else
		game->win->player_sprite = sprites->player_down;
	game->win->ply_priority = 1;
	game->win->ply_frame = 0;
}

void	move_right(t_game *game)
{
	int		x;
	int		y;

	x = game->player->coords.x;
	y = game->player->coords.y;
	if (x + 1 == game->map->column)
		return ;
	if (game->map->matrix[y][x + 1] == '1')
		return ;
	if (game->map->matrix[y][x + 1] == 'E' && \
	game->player->ncolect != game->player->ncolect)
		return ;
	if ((game->map->matrix[y][x + 1] == 'E' && \
	game->player->ncolect == game->map->nconsum) || \
	game->map->matrix[y][x + 1] == 'M')
		end_game (game->win);
	game->map->matrix[y][x] = '0';
	if (game->map->matrix[y][x + 1] == 'C')
		(game->player->ncolect)++;
	game->map->matrix[y][x + 1] = 'P';
	(game->steps)++;
	(game->player->coords.x++);
	print_steps (game);
	set_sprite_pos (game, 1);
}

void	move_left(t_game *game)
{
	int		x;
	int		y;

	x = game->player->coords.x;
	y = game->player->coords.y;
	if (x - 1 == game->map->column)
		return ;
	if (game->map->matrix[y][x - 1] == '1')
		return ;
	if (game->map->matrix[y][x - 1] == 'E' && \
	game->player->ncolect != game->player->ncolect)
		return ;
	if ((game->map->matrix[y][x - 1] == 'E' && \
	game->player->ncolect == game->map->nconsum) || \
	game->map->matrix[y][x - 1] == 'M')
		end_game (game->win);
	game->map->matrix[y][x] = '0';
	if (game->map->matrix[y][x - 1] == 'C')
		(game->player->ncolect)++;
	game->map->matrix[y][x - 1] = 'P';
	(game->steps)++;
	(game->player->coords.x--);
	print_steps (game);
	set_sprite_pos (game, 2);
}

void	move_down(t_game *game)
{
	int		x;
	int		y;

	x = game->player->coords.x;
	y = game->player->coords.y;
	if (y + 1 == game->map->column)
		return ;
	if (game->map->matrix[y + 1][x] == '1')
		return ;
	if (game->map->matrix[y + 1][x] == 'E' && \
	game->player->ncolect != game->player->ncolect)
		return ;
	if ((game->map->matrix[y + 1][x] == 'E' && \
	game->player->ncolect == game->map->nconsum) || \
	game->map->matrix[y + 1][x] == 'M')
		end_game (game->win);
	game->map->matrix[y][x] = '0';
	if (game->map->matrix[y + 1][x] == 'C')
		(game->player->ncolect)++;
	game->map->matrix[y + 1][x] = 'P';
	(game->steps)++;
	(game->player->coords.y++);
	print_steps (game);
	set_sprite_pos (game, 3);
}

void	move_up(t_game *game)
{
	int		x;
	int		y;

	x = game->player->coords.x;
	y = game->player->coords.y;
	if (y - 1 == game->map->column)
		return ;
	if (game->map->matrix[y - 1][x] == '1')
		return ;
	if (game->map->matrix[y - 1][x] == 'E' && \
	game->player->ncolect != game->player->ncolect)
		return ;
	if ((game->map->matrix[y - 1][x] == 'E' && \
	game->player->ncolect == game->map->nconsum) || \
	game->map->matrix[y - 1][x] == 'M')
		end_game (game->win);
	game->map->matrix[y][x] = '0';
	if (game->map->matrix[y - 1][x] == 'C')
		(game->player->ncolect)++;
	game->map->matrix[y + 1][x] = 'P';
	(game->steps)++;
	(game->player->coords.y--);
	print_steps (game);
	set_sprite_pos (game, 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:30:19 by amiguel-          #+#    #+#             */
/*   Updated: 2024/02/26 17:44:49 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

#define PY_ANIM 2000

static void	print_player(t_win *win, int frame)
{
	if (win->ply_priority == 0)
	{
		win->player_sprite = win->sprites->player1;
		win->player_sprite = win->sprites->player2;
	}
	else if (win->ply_priority == 1 && win->ply_frame >= PY_ANIM)
	{
		if (!frame)
			win->player_sprite = win->sprites->player1;
		else
			win->player_sprite = win->sprites->player2;
		win->ply_priority = 0;
		win->ply_frame = 0;
	}
	else
		win->ply_frame++;
}

void	change_sprites(t_win *win, int frame)
{
	t_images	*sprites;

	sprites = win->sprites;
	print_player (win, frame);
	if (frame == 0)
	{
		win->wall_sprite = sprites->wall1;
		win->floor_sprite = sprites->back1;
		win->cons_sprite = sprites->cons1;
	}
	win->wall_sprite = sprites->wall2;
	win->floor_sprite = sprites->back2;
	win->cons_sprite = sprites->cons2;
}

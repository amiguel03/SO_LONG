/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:30:19 by amiguel-          #+#    #+#             */
/*   Updated: 2024/02/27 12:17:52 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

#define PY_ANIM 2000

static void	print_player(t_win *win, int frame)
{
	if (win->ply_priority == 0)
	{
		win->player_sprite = win->sprites->player;
	}
	else if (win->ply_priority == 1 && win->ply_frame >= PY_ANIM)
	{
		if (!frame)
			win->player_sprite = win->sprites->player;
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
		win->wall_sprite = sprites->wall;
		win->floor_sprite = sprites->back;
		win->cons_sprite = sprites->cons;
	}
}

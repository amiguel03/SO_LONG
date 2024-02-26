/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:52:55 by amiguel-          #+#    #+#             */
/*   Updated: 2024/02/26 17:52:47 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	print_sprites(t_win *win, int w, int h, void *sprite)
{
	w *= IMAGE_WEIGHT;
	h *= IMAGE_HEIGHT;
	
	mlx_put_image_to_window(win->mlx, win->win, sprite, w, h);
}

void	manage_sprites(t_win *win, int x, int y)
{
	change_sprites(win, win->frame);
	
if (win->map[y][x] == 'P')
	{
		print_sprites(win, x, y, win->floor_sprite);
		print_sprites(win, x, y, win->player_sprite);
	}
	else if (win->map[y][x] == '1')
		print_sprites(win, x, y, win->wall_sprite);
	else if (win->map[y][x] == 'C')
	{
		print_sprites(win, x, y, win->floor_sprite);
		print_sprites(win, x, y, win->cons_sprite);
	}
	else if (win->map[y][x] == 'E')
		print_sprites(win, x, y, win->end_sprite);
	else if (win->map[y][x] == 'M')
		print_sprites(win, x, y, win->floor_sprite);
	else
		print_sprites(win, x, y, win->floor_sprite);
}

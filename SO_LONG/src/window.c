/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:42:04 by amiguel-          #+#    #+#             */
/*   Updated: 2024/03/06 16:14:36 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	close_window(t_window *window)
{
	mlx_destroy_window(window->mlx, window->win);
	exit (0);
	return (0);
}

int	key_hook(int keycode, t_window *window)
{
	if (keycode == 53)
		close_window(window);
	else if (keycode == 13 || keycode == 126)
		move_up(window);
	else if (keycode == 2 || keycode == 124)
		move_right(window);
	else if (keycode == 1 || keycode == 125)
		move_down(window);
	else if (keycode == 0 || keycode == 123)
		move_left(window);
	return (0);
}

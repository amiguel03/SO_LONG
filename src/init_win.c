/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_win.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:07:12 by amiguel-          #+#    #+#             */
/*   Updated: 2024/02/21 15:15:50 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

# define FRAMES_CHANGE 50

int		render(t_win *win)
{
	int		x;
	int		y;
	char	*steps

	y = 0;
	win->count++;
	mlx_clear_window(win->mlx, win->win);
	if (win->win >= FRAMES_CHANGE)
	{
		win->count = 0;
		win->frame = (win->frame + 1) % 2;		
	}
	while (win->map[y])
	{
		x = 0;
		while (win->map[y][x])
			manage_sprites(win, x++, y);
		y++;
	}
	steps = ft_itoa(win->game->steps);
	mlx_string_put(win->mlx, win->win, 50, 50, 0xFFF, steps);
	free(steps);
	return (0)
}

int		end_game(t_win *win)
{
	mlx_destroy_window(win->mlx, win->win);
	print_end(win->game);
	exit(0);
}

int		key_hook(int key, t_win *win)
{
	if (key == ESC)
		end_game(win);
	if (key == A || key == LEFT)
		move_left(win->game);
	if (key == S || key == DOWN)
		move_down(win->game);
	if (key == D || key == RIGTH)
		move_right(win->game);
	if (key == W || key == UP)
		move_up(win->game);
	return (0);
}

static int set_prites(t_win win)
{
	int		w;
	int		h;
	void	*mlx;
	
	w = IMAGE_WEIGHT;
	h = IMAGE_HEIGHT;
	mlx = win->mlx;
	if(!push_images(win))
		return (0);
	change_sprites(win, 0);
	return (1);
}

t_win	*get_win(int columns, int rows)
{
	t_win	*win;
	int		weight;
	int		height;

	weight = IMAGE_WEIGHT *columns;
	height = IMAGE_HEIGHT *rows;
	win = (t_win *)malloc(sizeof(t_win));
	if (!win)
		return (NULL);
	win->mlx = mlx_init();
	win->sprites = (t_images *) malloc(sizeof(t_images));
	win->win = mlx_new_window(win->mlx, weight, height, "so long!");	
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:15:52 by amiguel-          #+#    #+#             */
/*   Updated: 2024/03/05 11:45:14 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	*push_player(t_win *win)
{
	int		w;
	int		h;
	void	*mlx;

	w = 244;
	h = 244;
	mlx = win->mlx;
	win->sprites->player = mlx_xpm_file_to_image(mlx, PLAYER, &w, &h);
	return (win->sprites->player);
}

static void	*push_wall(t_win *win)
{
	int		w;
	int		h;
	void	*mlx;

	w = IMAGE_WIDTH;
	h = IMAGE_HEIGHT;
	mlx = win->mlx;
	win->sprites->wall = mlx_xpm_file_to_image(mlx, WALL, &w, &h);
	return (win->sprites->wall);
}

static void	*push_back(t_win *win)
{
	int		w;
	int		h;
	void	*mlx;

	w = IMAGE_WIDTH;
	h = IMAGE_HEIGHT;
	mlx = win->mlx;
	win->sprites->back = mlx_xpm_file_to_image(mlx, BACK, &w, &h);
	return (win->sprites->back);
}

static void	*push_coll(t_win *win)
{
	int		w;
	int		h;
	void	*mlx;

	w = IMAGE_WIDTH;
	h = IMAGE_HEIGHT;
	mlx = win->mlx;
	win->sprites->cons = mlx_xpm_file_to_image(mlx, COLL, &w, &h);
	return (win->sprites->cons);
}

void	*push_images(t_win *win)
{
	int		w;
	int		h;
	void	*mlx;

	w = IMAGE_WIDTH;
	h = IMAGE_HEIGHT;
	mlx = win->mlx;
	if (!push_player(win) || !push_wall(win) || !push_back(win))
		return (0);
	if (!push_coll(win))
		return(0);
	win->end_sprite = mlx_xpm_file_to_image(mlx, DOOR_CLOSE, &h, &w);
	return(win->end_sprite);
}
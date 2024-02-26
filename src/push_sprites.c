/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:15:52 by amiguel-          #+#    #+#             */
/*   Updated: 2024/02/26 14:49:46 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	push_player(t_win *win)
{
	int		w;
	int		h;
	void	*mlx

	w = 244;
	h = 244;
	mlx = win->mlx;
	win->sprites->player1 = mlx_xpm_file_to_image(mlx, PLAYER1, &w, &h);
	win->sprites->player2 = mlx_xpm_file_to_image(mlx, PLAYER2, &w, &h);
	win->sprites->player_down = mlx_xpm_file_to_image(mlx, PLY_DN, &w, &h);
	win->sprites->player_up = mlx_xpm_file_to_image(mlx, PLY_UP, &w, &h);
	win->sprites->player_left = mlx_xpm_file_to_image(mlx, PLY_LF, &w, &h);
	win->sprites->player_right = mlx_xpm_file_to_image(mlx, PLY_RG, &w, &h);
	return (win->sprites->player1 && win->sprites->player2);
}

static int	push_wall(t_win *win)
{
	int		w;
	int		h;
	void	*mlx

	w = IMAGE_WEIGHT;
	h = IMAGE_HEIGHT;
	mlx = win->mlx;
	win->sprites->wall1 = mlx_xpm_file_to_image(mlx, WALL1, &w, &h);
	win->sprites->wall2 = mlx_xpm_file_to_image(mlx, WALL2, &w, &h);
	return (win->sprites->wall1 && win->sprites->wall2);
}

static int	push_back(t_win *win)
{
	int		w;
	int		h;
	void	*mlx

	w = IMAGE_WEIGHT;
	h = IMAGE_HEIGHT;
	mlx = win->mlx;
	win->sprites->back1 = mlx_xpm_file_to_image(mlx, BACK1, &w, &h);
	win->sprites->back2 = mlx_xpm_file_to_image(mlx, BACK2, &w, &h);
	return (win->sprites->back1 && win->sprites->back2);
}

static int	push_coll(t_win *win)
{
	int		w;
	int		h;
	void	*mlx

	w = IMAGE_WEIGHT;
	h = IMAGE_HEIGHT;
	mlx = win->mlx;
	win->sprites->coll1 = mlx_xpm_file_to_image(mlx, COLL1, &w, &h);
	win->sprites->coll2 = mlx_xpm_file_to_image(mlx, COLL2, &w, &h);
	return (win->sprites->coll1 && win->sprites->coll2);
}

int	push_images(t_win *win)
{
	int		w;
	int		h;
	void	*mlx

	w = IMAGE_WEIGHT;
	h = IMAGE_HEIGHT;
	mlx = win->mlx;
	if (!push_player(win) || !push_wall(win) || !push_back(win))
		return (0);
	if (!push_coll(win))
		return(0);
	win->end_sprite = mlx_xpm_file_to_image(mlx, DOOR_CLOSE, &h, &w);
	return(win->end_sprite);
}
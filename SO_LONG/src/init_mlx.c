/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:01:44 by amiguel-          #+#    #+#             */
/*   Updated: 2024/03/06 15:45:49 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_mlx(t_window *window, char **new_map)
{
	int	row;
	int	col;

	row = strlen_row(new_map);
	col = strlen_col(new_map[0]);
	window->mlx = mlx_init();
	if (!window->mlx)
		ft_error("Error\n.Error al inicializar la conexión gráfica.\n");
	window->win = mlx_new_window(window->mlx,
			col * SPRITE_SIZE, row * SPRITE_SIZE, "THE GAME");
	if (!window->win)
		ft_error("Error\n.Error al crear la ventana.\n");
}

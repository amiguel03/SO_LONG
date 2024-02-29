/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:48:41 by amiguel-          #+#    #+#             */
/*   Updated: 2024/02/29 16:27:32 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	leaks(void)
{
	system("leaks -q so_long");
}

int	check_extension(char *filename)
{
	int	length;

	length = ft_strlen(filename);
	if (filename[length - 1] == 'r' && \
		filename[length - 2] == 'e' && \
		filename[length - 3] == 'b' && \
		filename[length - 4] == '.')
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game	*game;

	atexit(leaks);
	if (argc != 2 || !check_extension(argv[1]))
		return (write(1, "Usage: ./so_long <map_file>.ber\n", 33));
	game = get_game(argv[1]);
	if (!game)
		return (1);
	printf("[ OK ]Juego iniciado %s\n", game->win->mlx);
	mlx_loop(game->win->mlx);
	exit(0);
}

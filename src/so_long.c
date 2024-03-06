/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:31:34 by amiguel-          #+#    #+#             */
/*   Updated: 2024/03/06 15:56:20 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	verify_extension(const char *str)
{
	int		len;
	int		i;
	char	*ext;

	i = 1;
	ext = ".ber";
	len = strlen_col(str);
	while (i <= 4)
	{
		if (str[len - i] != *(ext + (4 - i)))
			ft_error("Error\n.Extension invalida.\n");
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int			fd;
	t_window	window;
	t_game		game;

	if (argc == 2)
	{
		verify_extension(argv[1]);
		fd = open_map(argv[1]);
		setmap(fd, &game);
		window.game = &game;
		init_map(&window, game.map_copy);
		init_mlx(&window, game.map);
		print_sprites(&window, game.map);
		window.game->steps = 0;
		mlx_key_hook(window.win, key_hook, &window);
		mlx_hook(window.win, 17, 0, close_window, &window);
		mlx_loop(window.mlx);
		close(fd);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apuntes_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:32:01 by amiguel-          #+#    #+#             */
/*   Updated: 2024/02/27 15:55:13 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/so_long.h"

int	main(void)
{
	/*void	*mlx; // Programa principal, gesto de ventanas*/
	/*void	*win; // Ventana del juego que se abre*/
	void	*sprite; // La imagen que colocas en la ventana
	t_vars	vars;
	char	*relative_path = "./textures/background/back.xpm";
	int		img_width;
	int		img_height;

	/* Configurar las pantallas */
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	sprite = mlx_xpm_file_to_image(vars.mlx, relative_path, &img_width, &img_height);
	if (!sprite){
		printf("No se ha podido cargar el archivo!");
		exit (1);
	}
	mlx_put_image_to_window(vars.mlx, vars.win, sprite, 0, 0);

	mlx_key_hook(vars.win, key_hook, &vars);
	
	/* Iniciar la pantalla */
	mlx_loop(vars.mlx);
}
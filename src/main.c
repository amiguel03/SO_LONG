/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:48:41 by amiguel-          #+#    #+#             */
/*   Updated: 2024/02/20 11:54:12 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	print_error(char *msg)
{
	write(1, msg, ft_strlen(msg));
	return (1);
}

int main(int argc, char *argv[])
{
	t_game *ctrl;
	
	if (argc != 2)
		return (print_error(ARGUMENTS_ERROR_MSG));
	
	/* TODO: Inicializar la estructura principal */
	ctrl = init_data(argv[1]);
	if (ctrl)
		return (print_error(ERROR_INIT_MSG));
	
	/* TODO: plantear la logica de:
		- Los movimientos
		- Los hooks (teclas)
		- Recogida de objetos
		- El personaje llega al final
	*/
	// start_game(ctrl);
	
	return (0);
}

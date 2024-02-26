/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:48:41 by amiguel-          #+#    #+#             */
/*   Updated: 2024/02/26 16:59:28 by amiguel-         ###   ########.fr       */
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
	t_game *;
	
	if (argc != 2)
		return (print_error(ARGUMENTS_ERROR_MSG));
	
	if (ctrl)
		return (print_error(ERROR_INIT_MSG));
	
	return (0);
}

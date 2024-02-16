/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:05:53 by amiguel-          #+#    #+#             */
/*   Updated: 2024/02/14 15:39:14 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_controler *init_data(char *map_name)
{
	/* TODO: inicializar el mapa */	
		/* NOTE: cosas que tengo que hacer:
			-> Guardar el mapa en la matriz (gnl?)
			-> Guardar las dimensiones (antes de guardar todo el mapa)
			-> Sacar numero de coleccionables
				· Mirar que se un numero valido
			-> Guardar la entrada y la salida
				· Mirar que existen las dos
				· Mirar que sean validas
				· Mirar que no se solapen
			-> Mirar que el mapa es valido
				· Rodeado de paredes (character '1')
				· Mirar que el juego se pueda completar
					# Que se pueda llegar a la salida
					# Que se puedan conseguir todos los consumibles
		*/
	
	/* TODO: inicializar el personaje */
		/* NOTE: cosas que hacer 
			-> Guardar las coordenadas de aparicion del personaje (usando el mapa)
			-> Inicializar el numero consumibles
		*/
	/* TODO: inicializar el la pantalla */
		/* NOTE: cosas a completar:
			-> Crear el mlx
			-> Crear la ventana
			-> Guardar los sprites (array, estrucctura, variables en otros lados?)
		*/
		/* REVIEW: añadir los hooks y teclas aqui o en ejecucion?*/	

	
}
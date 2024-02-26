/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:20:09 by amiguel-          #+#    #+#             */
/*   Updated: 2024/02/26 17:52:04 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	*delete_player(t_player *player)
{
	if (!player)
		return (NULL);
	free (player);
	return (NULL);
}

t_player	*get_player(t_map *map)
{
	t_player	*player;

	if (!map)
		return (NULL);
	player = (t_player *)malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->coords.x = map->in.x;
	player->coords.y = map->in.y;
	player->ncolect = 0;
	return (player);
}

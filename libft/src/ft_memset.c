/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 10:48:18 by amiguel-          #+#    #+#             */
/*   Updated: 2023/09/12 09:23:38 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	index;
	char	*casted;

	index = 0;
	casted = (char *)str;
	while (index < n)
	{
		casted[index] = (unsigned char)c;
		index++;
	}
	return ((void *)casted);
}

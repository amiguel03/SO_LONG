/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 23:00:30 by amiguel-          #+#    #+#             */
/*   Updated: 2023/09/12 09:24:13 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *s)
{
	size_t	index;
	char	*memory;

	index = 0;
	memory = (char *) malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!memory)
		return (NULL);
	while (s[index])
	{
		memory[index] = s[index];
		index++;
	}
	memory[index] = '\0';
	return (memory);
}

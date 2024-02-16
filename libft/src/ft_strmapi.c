/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 00:34:07 by amiguel-          #+#    #+#             */
/*   Updated: 2023/09/12 09:24:47 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*memory;
	unsigned int	index;

	index = 0;
	if (!s || !f)
		return (NULL);
	memory = (char *) malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!memory)
		return (NULL);
	while (s[index])
	{
		memory[index] = f(index, s[index]);
		index++;
	}
	memory[index] = '\0';
	return (memory);
}

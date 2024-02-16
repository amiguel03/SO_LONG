/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:30:01 by amiguel-          #+#    #+#             */
/*   Updated: 2023/09/12 09:23:05 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*memory;

	memory = (t_list *) malloc(sizeof(t_list));
	if (!memory)
		return (NULL);
	memory->content = content;
	memory->next = NULL;
	return (memory);
}

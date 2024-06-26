/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:16:13 by amiguel-          #+#    #+#             */
/*   Updated: 2024/03/06 16:14:43 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	putnbr(int n)
{
	char	a;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else
	{
		if (n < 0)
		{
			write(1, "-", 1);
			n = (n * (-1));
		}
		if (n < 10)
		{
			a = n + '0';
			write(1, &a, 1);
		}
		else
		{
			putnbr(n / 10);
			a = (n % 10) + '0';
			write(1, &a, 1);
		}
	}
}

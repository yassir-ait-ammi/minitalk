/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 08:58:06 by yaait-am          #+#    #+#             */
/*   Updated: 2024/12/22 14:19:19 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb <= 0)
		write(1, "\nInvalid pid, most be more than zero\n\n", 38);
	else if (nb >= 10)
	{
		ft_putnbr((nb / 10));
		ft_putchar((nb % 10) + '0');
	}
	else
		ft_putchar(nb + 48);
}

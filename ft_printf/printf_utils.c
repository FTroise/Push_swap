/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroise <ftroise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 01:23:10 by francescotr       #+#    #+#             */
/*   Updated: 2023/03/16 21:16:05 by ftroise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int num)
{
	int		i;
	long	nb;

	nb = num;
	i = 0;
	if (nb < 0)
	{
		i += ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
		i += ft_putnbr(nb / 10);
	i += ft_putchar(nb % 10 + 48);
	return (i);
}

int	ft_hex_putnbr(unsigned long nb, char *s)
{
	int	i;

	i = 0;
	if (nb >= 16)
		i += ft_hex_putnbr(nb / 16, s);
	i += ft_putchar(s[nb % 16]);
	return (i);
}

int	ft_unsigned_putnbr(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb > 9)
		i += ft_putnbr(nb / 10);
	i += ft_putchar(nb % 10 + 48);
	return (i);
}

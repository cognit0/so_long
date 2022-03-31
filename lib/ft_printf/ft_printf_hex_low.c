/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex_low.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayalman <ayalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 02:24:32 by ardayalman        #+#    #+#             */
/*   Updated: 2022/02/19 18:10:36 by ayalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printhex(unsigned int quotient)
{
	char	temp;

	if (quotient != 0)
	{
		temp = quotient % 16;
		if (temp < 10)
			temp += '0';
		else
			temp += 87;
		ft_printhex(quotient / 16);
		ft_putchar(temp);
	}
}

void	ft_dec2hexlow(long int decimalNumber)
{
	long int	quotient;

	if (decimalNumber == 0)
		ft_putchar('0');
	if (decimalNumber < 0)
		quotient = UINT_MAX + decimalNumber + 1;
	else
		quotient = decimalNumber;
	ft_printhex(quotient);
}

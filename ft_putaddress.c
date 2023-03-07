/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:13:35 by fporciel          #+#    #+#             */
/*   Updated: 2023/03/07 09:40:23 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_puthexaddress(int ap, int hex_len)
{
	int		remainder;
	int		counter;
	char	*hexstr;
	char	hex_string[hex_len];

	counter = 0;
	while (ap > 0)
	{
		remainder = ap % 16;
		if (remainder < 10)
			hex_string[counter] = remainder + 48;
		else
			hex_string[counter] = remainder - 10 + 97;
		counter++;
		ap = ap / 16;
	}
	hexstr = &(hex_string[0]);
	return (ft_putstr(hexstr));
}

int	ft_putaddress(int ap)
{
	int	ap1;
	int	hex_len;
	int	result;

	ap1 = ap;
	hex_len = 0;
	while (ap1 > 0)
	{
		ap1 = ap1 / 16;
		hex_len++;
	}
	write(1, "0x", 2);
	result = 2;
	result = result + ft_puthexaddress(ap, hex_len);
	return (result);
}

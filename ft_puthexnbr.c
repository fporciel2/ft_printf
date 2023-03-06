/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:18:05 by fporciel          #+#    #+#             */
/*   Updated: 2023/03/06 13:34:51 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_reverse_hex_str(char *hex_string, int hex_len)
{
	int		i;
	int 	j;
	char	buff;

	i = 0;
	j = hex_len - 1;
	while (i < j)
	{
		buff = hex_string[i];
		hex_string[i] = hex_string[j];
		hex_string[j] = buff;
		i++;
		j--;
	}
	hex_string[hex_len] = 0;
	return (hex_string);
}

static int	ft_puthexaddress1(uintptr_t ap, int hex_len)
{
	int		remainder;
	int		counter;
	char	hex_string[hex_len];

	counter = 0;
	while (ap > 0)
	{
		remainder = ap % 16;
		if (remainder < 10)
			hex_string[counter] = remainder + 48;
		else
			hex_string[counter] = remainder - 10 + 65;
		counter++;
		ap = ap / 16;
	}
	hex_string = ft_reverse_hex_str(hex_string, hex_len);
	return (ft_putstr(hex_string));
}

static int	ft_puthexaddress(uintptr_t ap, int hex_len)
{
	int		remainder;
	int		counter;
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
	hex_string = ft_reverse_hex_str(hex_string, hex_len);
	return (ft_putstr(hex_string));
}

int	ft_puthexnbr(unsigned int ap, char formati)
{
	unsigned int	ap1;
	int				hex_len;
	int				remainder;
	int				result;

	ap1 = ap;
	hex_len = 0;
	result = 0;
	while (ap1 > 0)
	{
		ap1 = ap1 / 16;
		hex_len++;
	}
	if (formati == 'x')
		result = result + ft_puthexaddress(ap, hex_len);
	else if (formati == 'X')
		result = result + ft_puthexaddress1(ap, hex_len);
	return (result);
}

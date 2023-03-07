/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:18:05 by fporciel          #+#    #+#             */
/*   Updated: 2023/03/07 11:51:51 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_reverse_hex_str(char *hex_string, int hex_len)
{
	int		i;
	int		j;
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

static int	ft_puthexaddress1(unsigned int ap, int hex_len)
{
	int		remainder;
	int		counter;
	char	*hexstr;
	int		result;

	hexstr = (char *)malloc(sizeof(char) * hex_len);
	if (hexstr == NULL)
		return (0);
	counter = 0;
	while (ap > 0)
	{
		remainder = ap % 16;
		if (remainder < 10)
			hexstr[counter] = remainder + 48;
		else
			hexstr[counter] = remainder - 10 + 65;
		counter++;
		ap = ap / 16;
	}
	hexstr = ft_reverse_hex_str(hexstr, hex_len);
	result = ft_putstr(hexstr);
	ft_free_substrings(hexstr);
	return (result);
}

static int	ft_puthexaddress(unsigned int ap, int hex_len)
{
	int		remainder;
	int		counter;
	char	*hexstr;
	int		result;

	hexstr = (char *)malloc(sizeof(char) * hex_len);
	if (hexstr == NULL)
		return (0);
	counter = 0;
	while (ap > 0)
	{
		remainder = ap % 16;
		if (remainder < 10)
			hexstr[counter] = remainder + 48;
		else
			hexstr[counter] = remainder - 10 + 97;
		counter++;
		ap = ap / 16;
	}
	hexstr = ft_reverse_hex_str(hexstr, hex_len);
	result = ft_substr(hexstr);
	ft_free_substrings(hexstr);
	return (result);
}

int	ft_puthexnbr(unsigned int ap, char formati)
{
	unsigned int	ap1;
	int				hex_len;
	int				result;

	if (ap == 0)
	{
		write(1, "0", 1);
		return (1);
	}
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

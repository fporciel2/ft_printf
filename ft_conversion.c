/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:08:13 by fporciel          #+#    #+#             */
/*   Updated: 2023/03/07 09:28:39 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_conversion(const char *format, int *i, va_list ap)
{
	int	result;

	result = 0;
	(*i)++;
	if (format[(*i)] == 'c')
		result = result + ft_putchar(va_arg(ap, int));
	else if (format[(*i)] == 's')
		result = result + ft_putstr(va_arg(ap, char *));
	else if (format[(*i)] == 'p')
		result = result + ft_putaddress(va_arg(ap, int));
	else if ((format[(*i)] == 'd') || (format[(*i)] == 'i'))
		result = result + ft_putnbr(va_arg(ap, int));
	else if (format[(*i)] == 'u')
		result = result + ft_putunbr(va_arg(ap, unsigned int));
	else if ((format[(*i)] == 'x') || (format[(*i)] == 'X'))
		result = result + ft_puthexnbr(va_arg(ap, unsigned int), format[(*i)]);
	(*i)++;
	return (result);
}

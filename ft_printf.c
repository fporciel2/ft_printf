/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 09:50:38 by fporciel          #+#    #+#             */
/*   Updated: 2023/03/06 10:15:08 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_printf2(const char *format, int result, int *i)
{
	(*i)++;
	if (format[(*i)] == 37)
	{
		write(1, &(format[(*i)]), 1);
		result++;
	}
	(*i)++;
	return (result);
}

static int	ft_printf1(const char *format, va_list ap, int result)
{
	int	i;

	i = 0;
	while (format[i] != 0)
	{
		if (format[i] != 37)
		{
			write(1, &(format[i]), 1);
			result++;
			i++;
		}
		else if (ft_is_format_spec(format, i) == 0)
			i++;
		else if (ft_is_format_spec(format, i) == 1)
			result = result + ft_printf2(format, result, &i);
		else if (ft_is_format_spec(format, i) == 2)
			result = result + ft_conversion(format, &i, ap);
	}
	return (result);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		result;

	if ((format == NULL) || (format[0] == 0))
		return (0);
	va_start(ap, format);
	result = 0;
	result = ft_printf1(format, ap, result);
	va_end(ap);
	return (result);
}

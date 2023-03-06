/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_format_spec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:19:23 by fporciel          #+#    #+#             */
/*   Updated: 2023/03/06 10:25:29 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_is_format_spec(const char *format, int i)
{
	i++;
	if (format[i] == 37)
		return (1);
	else if ((format[i] == 'c') || (format[i] == 's') || (format[i] == 'p')
			|| (format[i] == 'd') || (format[i] == 'i') || (format[i] == 'u')
			|| (format[i] == 'x') || (format[i] == 'X'))
		return (2);
	else
		return (0);
}

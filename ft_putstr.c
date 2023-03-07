/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:59:08 by fporciel          #+#    #+#             */
/*   Updated: 2023/03/07 11:00:04 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *ap)
{
	int	result;

	result = 0;
	if (ap == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (ap[result])
		result++;
	ft_putstr_fd(ap, 1);
	return (result);
}

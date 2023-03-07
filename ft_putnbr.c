/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:51:56 by fporciel          #+#    #+#             */
/*   Updated: 2023/03/07 10:26:46 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr(int ap)
{
	int	ap1;
	int	result;

	if (ap == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	ap1 = ap;
	if (ap < 0)
	{
		ap1 = -ap1;
		result = 1;
	}
	else if (ap == 0)
		result = 1;
	else
		result = 0;
	while (ap1 > 0)
	{
		result++;
		ap1 = ap1 / 10;
	}
	ft_putnbr_fd(ap, 1);
	return (result);
}

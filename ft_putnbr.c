/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:51:56 by fporciel          #+#    #+#             */
/*   Updated: 2023/03/06 13:15:42 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr(int ap)
{
	int	ap1;
	int	result;

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
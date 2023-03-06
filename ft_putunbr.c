/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:08:49 by fporciel          #+#    #+#             */
/*   Updated: 2023/03/06 15:04:17 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putunbr(unsigned int ap)
{
	unsigned int	ap1;
	int				result;

	ap1 = ap;
	if (ap == 0)
		result = 1;
	else
		result = 0;
	while (ap1 > 0)
	{
		result++;
		ap1 = ap1 / 10;
	}
	ft_uputnbr_fd(ap, 1);
	return (result);
}

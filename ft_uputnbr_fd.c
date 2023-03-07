/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uputnbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:59:40 by fporciel          #+#    #+#             */
/*   Updated: 2023/03/07 11:00:58 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_writenbr(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_uputnbr_fd(unsigned int n, int fd)
{
	unsigned long int	i;

	i = n;
	if (i > 9)
	{
		ft_uputnbr_fd((i / 10), fd);
		ft_writenbr(((i % 10) + 48), fd);
	}
	else
		ft_writenbr((i + 48), fd);
}

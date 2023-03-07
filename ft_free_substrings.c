/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_substrings.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:52:44 by fporciel          #+#    #+#             */
/*   Updated: 2023/03/07 11:56:44 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_free_substrings(char *substring)
{
	size_t	subslen;

	subslen = ft_strlen(substring);
	while (subslen-- > 0)
		free(substring[subslen]);
	free(*substring);
	free(substring);
}

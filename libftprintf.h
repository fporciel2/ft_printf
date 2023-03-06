/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 09:48:08 by fporciel          #+#    #+#             */
/*   Updated: 2023/03/06 12:13:23 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include "libft.h"

int	ft_printf(const char *format, ...);
int	ft_is_format_spec(const char *format, int i);
int	ft_conversion(const char *format, int *i, va_list ap);
int	ft_putchar(int ap);
int	ft_putstr(char *ap);
int	ft_putaddress(uintptr_t ap);
int	ft_putnbr(int ap);
int	ft_putunbr(unsigned int ap);
int	ft_puthexnbr(unsigned int ap, char formati);

#endif

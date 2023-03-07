/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:53:00 by fporciel          #+#    #+#             */
/*   Updated: 2023/03/07 11:57:21 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "./libft/libft.h"

int		ft_printf(const char *format, ...);
int		ft_is_format_spec(const char *format, int i);
int		ft_conversion(const char *format, int *i, va_list ap);
int		ft_putchar(int ap);
int		ft_putstr(char *ap);
int		ft_putaddress(unsigned long long ap);
int		ft_putnbr(int ap);
int		ft_putunbr(unsigned int ap);
int		ft_puthexnbr(unsigned int ap, char formati);
void	ft_uputnbr_fd(unsigned int n, int fd);
void	ft_free_substrings(char *substring);

#endif

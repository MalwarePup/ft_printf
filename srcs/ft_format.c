/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:58:01 by ladloff           #+#    #+#             */
/*   Updated: 2022/11/04 20:47:48 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list *ap, const char format)
{
	size_t	len_args;

	len_args = 0;
	if (format == 'c')
		len_args += ft_printchar(va_arg(*ap, unsigned int));
	if (format == 's')
		len_args += ft_printstr(va_arg(*ap, char *));
	if (format == 'p')
		len_args += ft_printptr(va_arg(*ap, unsigned long));
	if (format == 'd' || format == 'i')
		len_args += ft_printdec(va_arg(*ap, int));
	if (format == 'u')
		len_args += ft_printudec(va_arg(*ap, unsigned int));
	if (format == 'x')
		len_args += ft_printhex_lower(va_arg(*ap, unsigned int));
	if (format == 'X')
		len_args += ft_printhex_upper(va_arg(*ap, unsigned int));
	if (format == '%')
		len_args += ft_printchar('%');
	return (len_args);
}

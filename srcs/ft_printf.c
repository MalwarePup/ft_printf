/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:54:11 by ladloff           #+#    #+#             */
/*   Updated: 2022/11/04 20:45:01 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	size_t	i;
	size_t	len_args;
	va_list	ap;

	i = -1;
	len_args = 0;
	va_start(ap, format);
	while (format[++i])
	{
		if (format[i] == '%')
			len_args += ft_format(&ap, format[++i]);
		else
			len_args += ft_printchar(format[i]);
	}
	return (len_args);
}

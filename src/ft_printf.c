/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:54:11 by ladloff           #+#    #+#             */
/*   Updated: 2023/04/10 12:18:38 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(va_list *ap, const char format, int *len_args)
{
	if (format == 'c')
		ft_printchar(va_arg(*ap, unsigned int), len_args);
	if (format == 's')
		ft_printstr(va_arg(*ap, char *), len_args);
	if (format == 'p')
		ft_printptr(va_arg(*ap, unsigned long), len_args);
	if (format == 'd' || format == 'i')
		ft_printdec(va_arg(*ap, int), len_args);
	if (format == 'u')
		ft_printudec(va_arg(*ap, unsigned int), len_args);
	if (format == 'x')
		ft_puthexa(va_arg(*ap, unsigned int), HEXA_LOWER_BASE, len_args);
	if (format == 'X')
		ft_puthexa(va_arg(*ap, unsigned int), HEXA_UPPER_BASE, len_args);
	if (format == '%')
		ft_printchar('%', len_args);
}

void	ft_puthexa(unsigned long n, const char *base, int *len_args)
{
	if (n >= 16)
	{
		ft_puthexa(n / 16, base, len_args);
		ft_puthexa(n % 16, base, len_args);
	}
	else if (n < 10)
		ft_printchar(base[n], len_args);
	else
		ft_printchar(base[n], len_args);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	ap;
	int		len_args;

	i = -1;
	len_args = 0;
	va_start(ap, format);
	while (format[++i])
	{
		if (format[i] == '%')
			ft_format(&ap, format[++i], &len_args);
		else
			ft_printchar(format[i], &len_args);
	}
	return (len_args);
}

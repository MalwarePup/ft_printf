/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex_upper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 20:54:36 by ladloff           #+#    #+#             */
/*   Updated: 2022/11/04 20:47:19 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_lenhex(unsigned long n)
{
	size_t	len;

	len = (n <= 0);
	while (n)
	{
		n /= 16;
		len++;
	}
	return (len);
}

void	ft_puthex_upper(unsigned long n)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (n >= 16)
	{
		ft_puthex_upper(n / 16);
		ft_puthex_upper(n % 16);
	}
	else if (n < 10)
		ft_printchar(base[n]);
	else
		ft_printchar(base[n]);
}

int	ft_printhex_upper(unsigned long n)
{
	size_t	len_args;

	len_args = 0;
	ft_puthex_upper(n);
	len_args += ft_lenhex(n);
	return (len_args);
}

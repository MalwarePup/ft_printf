/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex_lower.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 20:40:57 by ladloff           #+#    #+#             */
/*   Updated: 2022/11/04 20:47:34 by ladloff          ###   ########.fr       */
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

void	ft_puthex_lower(unsigned long n)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
	{
		ft_puthex_lower(n / 16);
		ft_puthex_lower(n % 16);
	}
	else if (n < 10)
		ft_printchar(base[n]);
	else
		ft_printchar(base[n]);
}

int	ft_printhex_lower(unsigned long n)
{
	size_t	len_args;

	len_args = 0;
	ft_puthex_lower(n);
	len_args += ft_lenhex(n);
	return (len_args);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex_lower.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 20:40:57 by ladloff           #+#    #+#             */
/*   Updated: 2023/04/07 20:57:02 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_lenhexa(unsigned long n)
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

void	ft_puthexa(unsigned long n, const char *base)
{
	if (n >= 16)
	{
		ft_puthexa(n / 16, base);
		ft_puthexa(n % 16, base);
	}
	else if (n < 10)
		ft_printchar(base[n]);
	else
		ft_printchar(base[n]);
}

int	ft_printhexa(unsigned long n, const char *base)
{
	size_t	len_args;

	len_args = 0;
	ft_puthexa(n, base);
	len_args += ft_lenhexa(n);
	return (len_args);
}

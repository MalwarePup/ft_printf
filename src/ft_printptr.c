/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:27:23 by ladloff           #+#    #+#             */
/*   Updated: 2023/02/26 15:23:09 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printptr(unsigned long n)
{
	size_t	len_args;

	len_args = 0;
	if (n > 0)
	{
		len_args += ft_printstr("0x");
		len_args += ft_printhex_lower(n);
	}
	else
		len_args += ft_printstr(NULL_POINTER_STR);
	return (len_args);
}

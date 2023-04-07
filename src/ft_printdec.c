/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:50:24 by ladloff           #+#    #+#             */
/*   Updated: 2022/11/04 20:47:43 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printdec(int n)
{
	size_t	len_str;
	char	*str;

	str = ft_itoa(n);
	len_str = ft_printstr(str);
	free(str);
	return (len_str);
}

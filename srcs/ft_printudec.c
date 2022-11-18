/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printudec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:01:05 by ladloff           #+#    #+#             */
/*   Updated: 2022/11/04 20:46:58 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printudec(unsigned int n)
{
	size_t	len_str;
	char	*str;

	str = ft_uitoa(n);
	len_str = ft_printstr(str);
	free(str);
	return (len_str);
}

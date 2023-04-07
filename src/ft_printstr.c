/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 20:41:26 by ladloff           #+#    #+#             */
/*   Updated: 2022/11/04 20:44:08 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *s)
{
	if (!s)
	{
		ft_printstr("(null)");
		return (6);
	}
	write(STDOUT_FILENO, s, ft_strlen(s));
	return (ft_strlen(s));
}

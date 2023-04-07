/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:50:16 by ladloff           #+#    #+#             */
/*   Updated: 2023/02/26 15:22:51 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifdef __APPLE__
#  define NULL_POINTER_STR "0x0"
# else
#  define NULL_POINTER_STR "(nil)"
# endif

# include <stdarg.h>
# include "libft.h"

/**
 * ft_printf.c
 */

int				ft_printf(const char *str, ...);

/**
 * ft_format.c
 */

int				ft_format(va_list *ap, const char format);

/**
 * ft_printchar.c
 */

int				ft_printchar(char c);

/**
 * ft_printstr.c
 */

int				ft_printstr(char *s);

/**
 * ft_printptr.c
 */

int				ft_printptr(unsigned long n);

/**
 * ft_printdec.c
 */

int				ft_printdec(int n);

/**
 * ft_printudec.c
 */

int				ft_printudec(unsigned int n);

/**
 * ft_printhex_lower.c
 */

void			ft_puthex_lower(unsigned long n);
int				ft_printhex_lower(unsigned long n);

/**
 * ft_printhex_upper.c
 */

void			ft_puthex_upper(unsigned long n);
int				ft_printhex_upper(unsigned long n);

#endif

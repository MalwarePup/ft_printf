/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:50:16 by ladloff           #+#    #+#             */
/*   Updated: 2023/04/07 20:52:45 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

# include <stdarg.h>

# ifdef __APPLE__
#  define NULL_POINTER_STR "0x0"
# else
#  define NULL_POINTER_STR "(nil)"
# endif

# define HEXA_LOWER_BASE "0123456789abcdef"
# define HEXA_UPPER_BASE "0123456789ABCDEF"

/**
 * ft_printf.c
 */

int		ft_printf(const char *str, ...)__attribute__((format(printf, 1, 2)));


/**
 * ft_format.c
 */

int			ft_format(va_list *ap, const char format);

/**
 * ft_printchar.c
 */

int			ft_printchar(char c);

/**
 * ft_printstr.c
 */

int			ft_printstr(char *s);

/**
 * ft_printptr.c
 */

int			ft_printptr(unsigned long n);

/**
 * ft_printdec.c
 */

int			ft_printdec(int n);

/**
 * ft_printudec.c
 */

int			ft_printudec(unsigned int n);

/**
 * ft_printhexa.c
 */

int			ft_printhexa(unsigned long n, const char *base);
void		ft_puthexa(unsigned long n, const char *base);

#endif

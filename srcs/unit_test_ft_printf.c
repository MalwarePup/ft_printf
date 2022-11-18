/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test_ft_printf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 21:09:58 by ladloff           #+#    #+#             */
/*   Updated: 2022/11/09 19:45:07 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <fcntl.h>
#include "ft_printf.h"

Test(format_char, test_single_param)
{
	int		out;
	char	*buffer;
	FILE	*fp;
	int	save_out;

	buffer = malloc(10 * sizeof(char));
	out = open("./result.log", O_RDWR);
	if (out == -1)
	{
		perror("Error while opening file");
		return ;
	}
	fp = fdopen(out, "r");
	if (!fp)
	{
		perror("ERROR");
		return ;
	}
	save_out = dup(fileno(stdout));
	if (-1 == dup2(out, fileno(stdout)))
	{
		perror("cannot redirect stdout");
		return ;
	}
	cr_expect(ft_printf("%c\n", 'c') == printf("%c\n", 'c'),
	"Expected output the character [c] and a return size of 2");
	fflush(stdout);
	//cr_expect(getline(&buffer, &bufsize, fp) == 'c');
	//result = getline(&buffer, &bufsize, fp);
	//printf("result {%zu}\n", result);
	close(out);
	close(save_out);
	ft_printf("%s\n", fgets(buffer, 1, fp));

}

/*
Test(format_char, test_single_param_space)
{
	cr_assert(ft_printf(" %c", 'c') == printf(" %c", 'c'),
	"Expected output the character [c] and a return size of 1");
}

Test(format_char, test_single_param_space2)
{
	cr_expect(ft_printf("%c ", 'c') == printf("%c ", 'c'),
	"Expected output the character [c ] and a return size of 2");
}

Test(format_char, test_two_param)
{
	cr_expect(ft_printf("%c %c", 'c', 'a') == printf("%c %c", 'c', 'a'),
	"Expected output the characters [c a] and return size of 3");
}

Test(format_char, test_two_param_spaces)
{
	cr_expect(ft_printf(" %c %c \n", 'c', 'a') == printf(" %c %c \n", 'c', 'a'),
	"Expected output the characters [ c a \n] and return size of 5");
}

Test(formar_char, test_three_param)
{
	cr_expect(ft_printf("%c%c%c\n", '0', '1', '2') == printf("%c%c%c\n", '0', '1', '2'),
	"Expected output the characters [012] and return size of 4");
}
*/


/*
Test(format_p, Test)
{
	char str[50] = "Hello World!";
	printf("\n%d :\n", printf("%p", str));
	printf("\n%d :\n", ft_printf("%p", str));
	printf("unsigned int: {%u}\n", -1);
	ft_printf("unsigned int: {%u}\n", -1);
}
*/

/*
void ft_conv_hex(unsigned long nb, char *base, char *p, size_t size)
{
	if (nb >= 16)
		ft_conv_hex(nb / 16, base, p, size - 1);
	p[size] = base[nb % 16];
}

int ft_putptr(unsigned long n)
{
	size_t len_args;
	size_t i;
	char *nb;

	nb = ft_itoa(p);
	printf("After itoa: [%s]\n", nb);
	len_args = 0;
	len_args += ft_putstr("0x");
	if (p == 0)
	{
		len_args += ft_putchar('0');
		return (len_args);
	}
	i = ft_get_len(p);
	ft_conv_hex(p, "0123456789abcdef", nb, i - 1);
	// printf("ft_strlen nb: {%zu}\n", ft_strlen(nb));
	// printf("I am the string: [%s]\n", nb);
	len_args += ft_putstr(nb);
	free(nb);
	return (len_args);
}
*/

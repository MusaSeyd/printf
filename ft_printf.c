/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcelesti <fcelesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:23:44 by fcelesti          #+#    #+#             */
/*   Updated: 2021/11/27 18:14:14 by fcelesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_selection(va_list ap, char c, int *j)
{
	if (c == 'c')
		*j += ft_putchar(va_arg(ap, int));
	if (c == 'd' || c == 'i')
		*j += ft_checkneg(va_arg(ap, int), "0123456789");
	if (c == 'u')
		*j += ft_putnbr(va_arg(ap, unsigned int), "0123456789");
	if (c == 's')
		*j += ft_putstr(va_arg(ap, char *));
	if (c == 'x')
		*j += ft_putnbr(va_arg(ap, unsigned int), "0123456789abcdef");
	if (c == 'X')
		*j += ft_putnbr(va_arg(ap, unsigned int), "0123456789ABCDEF");
	if (c == 'p')
	{
		*j += write(1, "0x", 2);
		*j += ft_putnbr(va_arg(ap, unsigned long), "0123456789abcdef");
	}
	if (c == '%')
		*j += write(1, "%", 1);
}

int	ft_printf(const char	*str, ...)
{
	int		i;
	int		j;
	va_list	ap;

	i = 0;
	j = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] != '%')
			j += ft_putchar(str[i]);
		else
		{
			i++;
			ft_selection(ap, str[i], &j);
		}
		i++;
	}
	return (j);
}

// int main ()
// {
// 	int x = 123456;
// 	// char	x[] = "abcd";
// 	// printf("%p\n\n", x);
// 	// size_t a = -1;
// 	// printf("my:\n");
// 	// printf("res: %d\n\noriginal:\n", ft_printf(" %u ", -2147483648));
// 	printf("res: %d\n\noriginal:\n", ft_printf("%d", x));
// 	// printf("\n");
// 	// printf("res: %d", printf(" %u ", -2147483648));
// 	// printf("%lu", a);
// }
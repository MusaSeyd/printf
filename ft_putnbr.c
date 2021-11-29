/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcelesti <fcelesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:23:47 by fcelesti          #+#    #+#             */
/*   Updated: 2021/11/27 18:15:57 by fcelesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

unsigned long	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_nbrlen(unsigned long n, int len)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= len;
		i++;
	}
	return (i);
}

int	ft_putnbr(unsigned long n, char	*str)
{
	int	a;

	if (n < ft_strlen(str))
		write(1, &str[n], 1);
	else
	{
		ft_putnbr(n / ft_strlen(str), str);
		a = (n % ft_strlen(str));
		write(1, &str[a], 1);
	}
	return (ft_nbrlen(n, ft_strlen(str)));
}

int	ft_checkneg(int n,	char *str)
{
	unsigned long	nb;

	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		write (1, "-", 1);
		nb = -n;
		return (ft_putnbr(nb, str) + 1);
	}
	else
	{
		nb = n;
		return (ft_putnbr(nb, str));
	}
}

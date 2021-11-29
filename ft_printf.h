/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcelesti <fcelesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 18:07:19 by fcelesti          #+#    #+#             */
/*   Updated: 2021/11/27 18:14:02 by fcelesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char	*str, ...);
int		ft_putchar(int c);
int		ft_putnbr(unsigned long n, char *str);
int		ft_putstr(char *s);
int		ft_checkneg(int n, char *str);
void	ft_selection(va_list ap, char c, int *j);

#endif
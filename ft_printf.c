/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 09:00:38 by yel-hajj          #+#    #+#             */
/*   Updated: 2022/11/11 10:47:39 by yel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printp(unsigned long long n, int *j)
{
	char	*p;

	p = "0123456789abcdef";
	if (n >= 16)
	{
		ft_printp(n / 16, j);
		n = n % 16;
	}
	ft_putchar(p[n], j);
}

void	check(const char *s, va_list list, int *j, int i)
{
	if (s[i + 1] == 'c')
		ft_putchar(va_arg(list, int), j);
	else if (s[i + 1] == 's')
		ft_putstr(va_arg(list, char *), j);
	else if (s[i + 1] == 'p')
	{
		ft_putstr("0x", j);
		ft_printp(va_arg(list, unsigned long long), j);
	}
	else if (s[i + 1] == 'd' || s[i + 1] == 'i')
		ft_putnbr(va_arg(list, int), j);
	else if (s[i + 1] == 'u')
		ft_putnbr(va_arg(list, unsigned int), j);
	else if (s[i + 1] == 'x' || s[i + 1] == 'X')
		printhex(va_arg(list, unsigned int), s[i +1], j);
	else if (s[i + 1] == '%')
		ft_putchar('%', j);
	else
	{
		ft_putchar(s[i + 1], j);
	}
}

int	ft_printf(const char *s, ...)
{
	va_list	list;
	int		i;
	int		j;

	j = 0;
	i = 0;
	va_start(list, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			check(s, list, &j, i);
			i += 2;
		}
		else
			ft_putchar(s[i++], &j);
	}
	va_end(list);
	return (j);
}

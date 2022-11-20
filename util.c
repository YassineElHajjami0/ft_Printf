/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:23:40 by yel-hajj          #+#    #+#             */
/*   Updated: 2022/11/09 14:56:46 by yel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char s, int *j)
{
	write(1, &s, 1);
	*j = *j + 1;
}

void	ft_putstr(char *c, int *j)
{
	int	i;

	i = 0;
	if (!c)
		c = "(null)";
	while (c[i])
	{
		write(1, &c[i++], 1);
		*j = *j + 1;
	}
}

void	ft_putnbr(long n, int *j)
{
	if (n < 0)
	{
		ft_putchar('-', j);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10, j);
		n = n % 10;
	}
	ft_putchar(n + 48, j);
}

void	printhex(unsigned int n, char format, int *j)
{
	char	*x;
	char	*mx;

	x = "0123456789abcdef";
	mx = "0123456789ABCDEF";
	if (n >= 16)
	{
		printhex(n / 16, format, j);
		n = n % 16;
	}
	if (format == 'x')
		ft_putchar(x[n], j);
	else
		ft_putchar(mx[n], j);
}

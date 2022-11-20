/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:11:29 by yel-hajj          #+#    #+#             */
/*   Updated: 2022/11/09 14:55:39 by yel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

void	ft_printp(unsigned long long n, int *j);
int		ft_printf(const char *s, ...);
void	ft_putchar(char s, int *j);
void	ft_putstr(char *c, int *j);
void	ft_putnbr(long n, int *j);
void	printhex(unsigned int n, char format, int *j);

#endif

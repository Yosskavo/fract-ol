/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:16:52 by yel-mota          #+#    #+#             */
/*   Updated: 2024/12/29 14:23:13 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexa(va_list one, char c)
{
	int	i;

	i = 0;
	if (c == 'x')
	{
		i = ft_putnbr_base(va_arg(one, unsigned int), "0123456789abcdef");
		return (i);
	}
	if (c == 'X')
	{
		i = ft_putnbr_base(va_arg(one, unsigned int), "0123456789ABCDEF");
		return (i);
	}
	if (c == 'p')
	{
		i = ft_putaddress(va_arg(one, void *));
		return (i);
	}
	return (i);
}

int	ft_putone(va_list one, const char str)
{
	if (str == '\0')
		return (-1);
	if (str == 's')
		return (ft_putstr(va_arg(one, char *)));
	if (str == 'c')
		return (ft_putchar(va_arg(one, int)));
	if (str == 'd' || str == 'i')
		return (ft_nbr(va_arg(one, int)));
	if (str == '%')
		return (ft_putchar('%'));
	if (str == 'x' || str == 'X' || str == 'p')
		return (ft_hexa(one, str));
	if (str == 'u')
		return (ft_unint(va_arg(one, unsigned int)));
	else
		return (ft_putchar('%') + ft_putchar(str));
}

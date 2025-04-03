/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:38:18 by yel-mota          #+#    #+#             */
/*   Updated: 2024/12/29 14:30:00 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_adress(unsigned long nbr)
{
	int				i;
	char			*base;
	unsigned int	basel;

	i = 0;
	base = "0123456789abcdef";
	basel = 16;
	if (nbr < basel)
	{
		i += ft_putchar(base[nbr]);
	}
	else
	{
		i += ft_adress(nbr / basel);
		i += ft_adress(nbr % basel);
	}
	return (i);
}

int	ft_putaddress(void *p)
{
	int	i;

	if (p == 0)
		return (ft_putstr("(nil)"));
	i = 0;
	i += ft_putstr("0x");
	i += ft_adress((unsigned long)p);
	return (i);
}

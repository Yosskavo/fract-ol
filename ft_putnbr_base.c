/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:37:01 by yel-mota          #+#    #+#             */
/*   Updated: 2024/12/29 13:54:27 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	int				i;
	unsigned int	basel;

	i = 0;
	basel = ft_strlen(base);
	if (nbr < basel)
	{
		i += ft_putchar(base[nbr]);
	}
	else
	{
		i += ft_putnbr_base(nbr / basel, base);
		i += ft_putnbr_base(nbr % basel, base);
	}
	return (i);
}

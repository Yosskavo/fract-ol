/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:44:42 by yel-mota          #+#    #+#             */
/*   Updated: 2025/04/04 14:21:17 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
int	ft_putnbr_base(unsigned int nbr, char *base);
int	ft_putchar(const char c);
int	ft_putstr(char *str);
int	ft_unint(unsigned int n);
int	ft_printf(const char *str, ...);
int	ft_countnbr(unsigned int n);
int	ft_putone(va_list one, const char str);
int	ft_nbr(int n);
int	ft_putaddress(void *p);

#endif

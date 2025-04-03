/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:44:42 by yel-mota          #+#    #+#             */
/*   Updated: 2024/12/29 16:28:08 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>

int	ft_putnbr_base(unsigned int nbr, char *base);
int	ft_putchar(const char c);
int	ft_putstr(char *str);
int	ft_unint(unsigned int n);
int	ft_printf(const char *str, ...);
int	ft_countnbr(unsigned int n);
int	ft_putone(va_list one, const char str);
int	ft_nbr(int n);
int	ft_strlen(const char *str);
int	ft_putaddress(void *p);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 23:10:02 by yel-mota          #+#    #+#             */
/*   Updated: 2025/04/09 23:10:03 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	m;
	size_t	i;

	i = ft_strlen(src);
	m = 0;
	if (size != 0)
	{
		while (src[m] != '\0' && m < size - 1)
		{
			dest[m] = src[m];
			m++;
		}
		dest[m] = '\0';
	}
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putimage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:27:08 by yel-mota          #+#    #+#             */
/*   Updated: 2025/04/09 09:47:42 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_putimage(t_data *data)
{
    data->i = 0;
    data->j = 0;
    while (data->map[data->i])
    {
        ft_printf("%s\n", data->map[data->i]);
        data->i++;
    }
}
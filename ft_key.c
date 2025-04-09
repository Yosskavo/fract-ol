/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:03:22 by yel-mota          #+#    #+#             */
/*   Updated: 2025/04/09 09:58:02 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_escape(t_data *data)
{
    ft_free_map(data->map);
	ft_free_1(data->y_init, data->y_wind, 0);
}

void ft_up(t_data *data)
{
    int new_y;
    int new_x;

    new_y = data->y_player - 1;
    new_x = data->x_player;
    if (data->map[new_y][new_x] == WALLS)
        return ;
    if (data->map[data->y_player][data->x_player] == data->map[data->y_exit][data->x_exit])
    {
        data->map[data->y_player][data->x_player] = EXIT;
        data->map[new_y][new_x] = PLAYER;
    }
    else 
    {
        data->map[data->y_player][data->x_player] = FREESPACE;
        data->map[new_y][new_x] = PLAYER;
    }
    data->y_player = new_y;
    data->x_player = new_x;
}

void ft_down(t_data *data)
{
    int new_y;
    int new_x;
    
    new_y = data->y_player + 1;
    new_x = data->x_player;
    if (data->map[new_y][new_x] == WALLS)
        return ;
    if (data->map[data->y_player][data->x_player] == data->map[data->y_exit][data->x_exit])
    {
        data->map[data->y_player][data->x_player] = EXIT;
        data->map[new_y][new_x] = PLAYER;
    }
    else 
    {
        data->map[data->y_player][data->x_player] = FREESPACE;
        data->map[new_y][new_x] = PLAYER;
    }
    data->y_player = new_y;
    data->x_player = new_x;
}

void ft_left(t_data *data)
{
    int new_y;
    int new_x;

    new_y = data->y_player;
    new_x = data->x_player - 1;
    if (data->map[new_y][new_x] == WALLS)
        return ;
    if (data->map[data->y_player][data->x_player] == data->map[data->y_exit][data->x_exit])
    {
        data->map[data->y_player][data->x_player] = EXIT;
        data->map[new_y][new_x] = PLAYER;
    }
    else 
    {
        data->map[data->y_player][data->x_player] = FREESPACE;
        data->map[new_y][new_x] = PLAYER;
    }
    data->y_player = new_y;
    data->x_player = new_x;
}

void ft_right(t_data *data)
{
    int new_y;
    int new_x;

    new_y = data->y_player;
    new_x = data->x_player + 1;
    if (data->map[new_y][new_x] == WALLS)
        return ;
    if (data->map[data->y_player][data->x_player] == data->map[data->y_exit][data->x_exit])
    {
        data->map[data->y_player][data->x_player] = EXIT;
        data->map[new_y][new_x] = PLAYER;
    }
    else 
    {
        data->map[data->y_player][data->x_player] = FREESPACE;
        data->map[new_y][new_x] = PLAYER;
    }
    data->y_player = new_y;
    data->x_player = new_x;
}
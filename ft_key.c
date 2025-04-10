/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:03:22 by yel-mota          #+#    #+#             */
/*   Updated: 2025/04/09 22:50:45 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_collect(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == COLLECT)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_up(t_data *data, char **map, int *i)
{
	int	new_y;
	int	new_x;

	new_y = data->y_player - 1;
	new_x = data->x_player;
	if (map[new_y][new_x] == WALLS)
		return ;
	if (map[new_y][new_x] == EXIT && !ft_collect(map))
		ft_escape(data);
	if (map[data->y_player][data->x_player] == map[data->y_exit][data->x_exit])
	{
		map[data->y_player][data->x_player] = EXIT;
		map[new_y][new_x] = PLAYER;
	}
	else
	{
		map[data->y_player][data->x_player] = FREESPACE;
		map[new_y][new_x] = PLAYER;
	}
	ft_printf("Moves : %d\n", ++(*i));
	data->y_player = new_y;
	data->x_player = new_x;
}

void	ft_down(t_data *data, char **map, int *i)
{
	int	new_y;
	int	new_x;

	new_y = data->y_player + 1;
	new_x = data->x_player;
	if (map[new_y][new_x] == WALLS)
		return ;
	if (map[new_y][new_x] == EXIT && !ft_collect(map))
		ft_escape(data);
	if (map[data->y_player][data->x_player] == map[data->y_exit][data->x_exit])
	{
		map[data->y_player][data->x_player] = EXIT;
		map[new_y][new_x] = PLAYER;
	}
	else
	{
		map[data->y_player][data->x_player] = FREESPACE;
		map[new_y][new_x] = PLAYER;
	}
	ft_printf("Moves : %d\n", ++(*i));
	data->y_player = new_y;
	data->x_player = new_x;
}

void	ft_left(t_data *data, char **map, int *i)
{
	int	new_y;
	int	new_x;

	new_y = data->y_player;
	new_x = data->x_player - 1;
	if (map[new_y][new_x] == WALLS)
		return ;
	if (map[new_y][new_x] == EXIT && !ft_collect(data->map))
		ft_escape(data);
	if (map[data->y_player][data->x_player] == map[data->y_exit][data->x_exit])
	{
		map[data->y_player][data->x_player] = EXIT;
		map[new_y][new_x] = PLAYER;
	}
	else
	{
		map[data->y_player][data->x_player] = FREESPACE;
		map[new_y][new_x] = PLAYER;
	}
	ft_printf("Moves : %d\n", ++(*i));
	data->y_player = new_y;
	data->x_player = new_x;
}

void	ft_right(t_data *data, char **map, int *i)
{
	int	new_y;
	int	new_x;

	new_y = data->y_player;
	new_x = data->x_player + 1;
	if (map[new_y][new_x] == WALLS)
		return ;
	if (map[new_y][new_x] == EXIT && !ft_collect(data->map))
		ft_escape(data);
	if (map[data->y_player][data->x_player] == map[data->y_exit][data->x_exit])
	{
		map[data->y_player][data->x_player] = EXIT;
		map[new_y][new_x] = PLAYER;
	}
	else
	{
		map[data->y_player][data->x_player] = FREESPACE;
		map[new_y][new_x] = PLAYER;
	}
	ft_printf("Moves : %d\n", ++(*i));
	data->y_player = new_y;
	data->x_player = new_x;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:21:58 by yel-mota          #+#    #+#             */
/*   Updated: 2025/04/09 15:42:17 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_len(char **str)
{
	int		i;
	size_t	len;

	i = 1;
	len = ft_strlen(str[0]);
	while (str[i] != NULL)
	{
		if (ft_strlen(str[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_walls(char **map, int len)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(map[0]);
	while (map[0][i] != '\0')
	{
		if (map[0][i] != WALLS || map[len - 1][i] != WALLS)
			return (0);
		i++;
	}
	i = 1;
	while (map[i] != NULL)
	{
		if (map[i][0] != WALLS || map[i][j - 1] != WALLS)
			return (0);
		i++;
	}
	return (1);
}

static int	ft_cond(int e, int p, int c)
{
	if (e != 1 || p != 1 || c < 1)
		return (0);
	return (1);
}

static void	ft_condtwo(int *p, int *e, t_data *data)
{
	if (data->map[data->i][data->j] == PLAYER)
	{
		data->x_player = data->j;
		data->y_player = data->i;
		(*p)++;
	}
	else if (data->map[data->i][data->j] == EXIT)
	{
		data->x_exit = data->j;
		data->y_exit = data->i;
		(*e)++;
	}
	else if (data->map[data->i][data->j] == COLLECT)
		data->c_count++;
}

int	ft_check_comp(t_data *data)
{
	int	e;
	int	p;

	data->i = 1;
	e = 0;
	p = 0;
	while (data->map[data->i] != NULL)
	{
		data->j = 1;
		while (data->map[data->i][data->j] != '\0')
		{
			if (data->map[data->i][data->j] == PLAYER
				|| data->map[data->i][data->j] == COLLECT
				|| data->map[data->i][data->j] == EXIT)
				ft_condtwo(&p, &e, data);
			else if (data->map[data->i][data->j] != FREESPACE
				&& data->map[data->i][data->j] != WALLS)
				return (0);
			data->j++;
		}
		data->i++;
	}
	return (ft_cond(e, p, data->c_count));
}

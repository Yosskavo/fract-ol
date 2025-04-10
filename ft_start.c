/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 08:17:41 by yel-mota          #+#    #+#             */
/*   Updated: 2025/04/09 23:05:11 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_maplen(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	ft_start(t_data *data)
{
	data->y_init = mlx_init();
	if (!data->y_init)
	{
		ft_error_close(ft_free_map(data->map), INIT_ERROR, -1);
	}
	data->y_wind = mlx_new_window(data->y_init, ft_strlen(data->map[0]) * HIGHT,
			ft_maplen(data->map) * WIDTH, GAME_NAME);
	if (!data->y_wind)
	{
		ft_free_map(data->map);
		ft_putstr_fd(WINDOW_ERROR, 2);
		ft_free_1(data->y_init, NULL, 1);
	}
	ft_putxpm(data);
	ft_putimage(data);
	mlx_hook(data->y_wind, 2, 1L << 0, key_handler, data);
	mlx_hook(data->y_wind, 17, 0, close_wind, data);
	mlx_loop(data->y_init);
}

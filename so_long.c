/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:22:52 by yel-mota          #+#    #+#             */
/*   Updated: 2025/04/09 22:49:37 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_escape(t_data *data)
{
	if (data->y_c)
		mlx_destroy_image(data->y_init, data->y_c);
	if (data->y_w)
		mlx_destroy_image(data->y_init, data->y_w);
	if (data->y_e)
		mlx_destroy_image(data->y_init, data->y_e);
	if (data->y_p)
		mlx_destroy_image(data->y_init, data->y_p);
	if (data->y_s)
		mlx_destroy_image(data->y_init, data->y_s);
	ft_free_map(data->map);
	ft_free_1(data->y_init, data->y_wind, 0);
}

void	ft_free_1(void *y_init, void *y_wind, int status_exit)
{
	if (y_wind != NULL)
		mlx_destroy_window(y_init, y_wind);
	if (y_init != NULL)
	{
		mlx_destroy_display(y_init);
		free(y_init);
	}
	exit(status_exit);
}

int	key_handler(int key, void *ptr)
{
	t_data		*data;
	static int	i;

	data = (t_data *)ptr;
	if (key == XK_Escape)
		ft_escape(data);
	if (key == XK_w)
		ft_up(data, data->map, &i);
	if (key == XK_s)
		ft_down(data, data->map, &i);
	if (key == XK_d)
		ft_right(data, data->map, &i);
	if (key == XK_a)
		ft_left(data, data->map, &i);
	ft_putimage(data);
	return (0);
}

int	close_wind(void *ptr)
{
	t_data	*data;

	data = (t_data *)ptr;
	ft_escape(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (ft_putstr_fd(INPUT_ERROR, 2), 1);
	ft_memset(&data, 0, sizeof(t_data));
	ft_check(av[1], &data);
	ft_start(&data);
}

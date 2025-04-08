/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:22:52 by yel-mota          #+#    #+#             */
/*   Updated: 2025/04/08 16:22:53 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_1(void *y_init, void *y_wind)
{
	mlx_destroy_window(y_init, y_wind);
	mlx_destroy_display(y_init);
	free(y_init);
	exit(0);
}

int	key_handler(int key, void *ptr)
{
	t_data	*halo;

	halo = (t_data *)ptr;
	if (key == XK_Escape)
	{
		ft_free_map(halo->map);
		ft_free_1(halo->y_init, halo->y_wind);
	}
	return (0);
}

int	close_wind(void *ptr)
{
	t_data	*halo;

	halo = (t_data *)ptr;
	ft_free_map(halo->map);
	ft_free_1(halo->y_init, halo->y_wind);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (ft_printf("input: ./so_long <map.ber>\n"), 1);
	ft_memset(&data, 0, sizeof(t_data));
	ft_check(av[1], &data);
	data.y_init = mlx_init();
	data.y_wind = mlx_new_window(data.y_init, 600, 600, "so_long");
	mlx_hook(data.y_wind, 2, 1L << 0, key_handler, &data);
	mlx_hook(data.y_wind, 17, 0, close_wind, &data);
	mlx_loop(data.y_init);
	ft_free_1(data.y_init, data.y_wind);
}

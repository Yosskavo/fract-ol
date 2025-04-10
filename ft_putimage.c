/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putimage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:27:08 by yel-mota          #+#    #+#             */
/*   Updated: 2025/04/09 16:04:26 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_error(t_data *data)
{
	ft_putstr_fd(IMAGE_ERROR, 2);
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
	ft_free_1(data->y_init, data->y_wind, 1);
}

void	ft_putxpm(t_data *data)
{
	int	i;
	int	j;

	data->y_c = mlx_xpm_file_to_image(data->y_init, "xpm/album.xpm", &i, &j);
	if (!data->y_c)
		ft_error(data);
	data->y_e = mlx_xpm_file_to_image(data->y_init, "xpm/nather_portale.xpm",
			&i, &j);
	if (!data->y_e)
		ft_error(data);
	data->y_p = mlx_xpm_file_to_image(data->y_init, "xpm/lier.xpm", &i, &j);
	if (!data->y_p)
		ft_error(data);
	data->y_w = mlx_xpm_file_to_image(data->y_init, "xpm/walls.xpm", &i, &j);
	if (!data->y_w)
		ft_error(data);
	data->y_s = mlx_xpm_file_to_image(data->y_init, "xpm/freespace.xpm", &i,
			&j);
	if (!data->y_s)
		ft_error(data);
}

void	ft_putimage(t_data *data)
{
	data->i = 0;
	while (data->map[data->i])
	{
		data->j = 0;
		while (data->map[data->i][data->j])
		{
			if (data->map[data->i][data->j] == PLAYER)
				mlx_put_image_to_window(data->y_init, data->y_wind, data->y_p,
					HIGHT * data->j, WIDTH * data->i);
			else if (data->map[data->i][data->j] == WALLS)
				mlx_put_image_to_window(data->y_init, data->y_wind, data->y_w,
					HIGHT * data->j, WIDTH * data->i);
			else if (data->map[data->i][data->j] == FREESPACE)
				mlx_put_image_to_window(data->y_init, data->y_wind, data->y_s,
					HIGHT * data->j, WIDTH * data->i);
			else if (data->map[data->i][data->j] == COLLECT)
				mlx_put_image_to_window(data->y_init, data->y_wind, data->y_c,
					HIGHT * data->j, WIDTH * data->i);
			else if (data->map[data->i][data->j] == EXIT)
				mlx_put_image_to_window(data->y_init, data->y_wind, data->y_e,
					HIGHT * data->j, WIDTH * data->i);
			data->j++;
		}
		data->i++;
	}
}

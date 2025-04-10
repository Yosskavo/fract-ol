/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:01:06 by yel-mota          #+#    #+#             */
/*   Updated: 2025/04/09 16:07:39 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**ft_tabcpy(char **map)
{
	char	**dest;
	int		i;

	i = 0;
	while (map[i] != NULL)
		i++;
	dest = malloc(sizeof(char *) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (map[i] != NULL)
	{
		dest[i] = ft_strdup(map[i]);
		if (!dest)
			return ((char **)ft_free_map(dest));
		i++;
	}
	dest[i] = NULL;
	return (dest);
}

static void	ft_flood(char **map, int y, int x)
{
	if (map[y][x] == WALLS)
		return ;
	map[y][x] = WALLS;
	ft_flood(map, y, x + 1);
	ft_flood(map, y, x - 1);
	ft_flood(map, y + 1, x);
	ft_flood(map, y - 1, x);
}

static int	flood_is(char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j] != NULL)
	{
		i = 0;
		while (map[j][i] != '\0')
		{
			if (map[j][i] != WALLS && map[j][i] != FREESPACE)
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	ft_fllod_fill(t_data *data)
{
	char	**str;

	str = ft_tabcpy(data->map);
	if (!str)
		return (0);
	ft_flood(str, data->y_player, data->x_player);
	if (!flood_is(str))
		return (ft_free_map(str), 0);
	ft_free_map(str);
	return (1);
}

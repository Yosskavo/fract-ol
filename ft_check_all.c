#include "so_long.h"

int	ft_check_len(char **str)
{
	int (i), (len);

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
	int (i), (j);
	i = 0;
	j = ft_strlen(map[0]);
	while (map[0][i] != '\0')
	{
		if (map[0][i] != WALLS || map[len - 1][i] != WALLS)
			return (0);
		i++;
	}
	i = 1;
	while (i < len - 2)
	{
		if (map[i][0] != WALLS || map[i][j - 1] != WALLS)
			return (0);
		i++;
	}
	return (1);
}

int ft_check_comp(t_data *data)
{
	int (i), (j), (p), (e);
	i = 1;
	e = 0;
	p = 0;
	while (data->map[i] != NULL)
	{
		j = 1;
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == PLAYER)
			{
				data->x_player = j;
				data->y_player = i;
				p++;
			}
			else if (data->map[i][j] == EXIT)
			{
				data->x_exit = j;
				data->y_exit = i;
				e++;
			}
			else if (data->map[i][j] == COLLECT)
				data->c_count++;
			else if (data->map[i][j] != FREESPACE && data->map[i][j] != WALLS)
				return (0);
			j++;
		}
		i++;
	}
	if (e != 1 || p != 1 || data->c_count < 1)
		return (0);
	return (1);

}


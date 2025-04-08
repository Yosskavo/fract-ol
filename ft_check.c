/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:22:03 by yel-mota          #+#    #+#             */
/*   Updated: 2025/04/08 16:22:04 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_all(t_data *data)
{
	int	len;

	len = ft_tablen((const char **)data->map);
	if (!ft_check_len(data->map))
		ft_error_close(ft_free_map(data->map), "the shape of map incoerrect \n",
			-1);
	if (!ft_check_walls(data->map, len))
		ft_error_close(ft_free_map(data->map), "messing walls \n", -1);
	if (!ft_check_comp(data))
		ft_error_close(ft_free_map(data->map), "messing or more P, 0,
			E or C \n", -1);
	if (!ft_fllod_fill(data))
		ft_error_close(ft_free_map(data->map), "invalide map \n", -1);
}

char	**ft_check_content(int fd)
{
	char *(tmp), *(cont), **(map);
	int(i);
	cont = ft_strdup("");
	if (!cont)
		ft_error_close(NULL, "failed in allocation !\n", fd);
	tmp = ft_strdup(" ");
	if (!tmp)
		ft_error_close(cont, "failed in allocation !!!\n", fd);
	i = 1;
	while (i > 0)
	{
		i = read(fd, tmp, 1);
		if (i == 0)
			break ;
		if (i < 0)
			ft_free_all(cont, tmp, "failed in read \n", fd);
		cont = ft_strjoin(cont, tmp);
		if (!cont)
			ft_error_close(tmp, "failed in allocation !! \n", fd);
	}
	free(tmp);
	if (ft_strnstr(cont, "\n\n", ft_strlen(cont)))
		ft_error_close(cont, "there is a new line in your map\n", fd);
	close(fd);
	map = ft_split(cont, '\n');
	free(cont);
	return (map);
}

int	ft_check_filename(char *filename)
{
	int	i;
	int	fd;

	i = ft_strlen(filename) - ft_strlen(EXTENSION);
	if (i <= 0 || filename[i - 1] == '/')
		ft_error_0("invalid map name or wrong extension");
	if (!ft_strcmp(filename + i, EXTENSION))
		ft_error_0("wrong or no extension");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error_0("no such a file or permission denied");
	return (fd);
}

void	ft_check(char *filename, t_data *data)
{
	int		fd;
	char	**map;

	fd = ft_check_filename(filename);
	map = ft_check_content(fd);
	if (!map)
		ft_error_close(ft_free_map(map), "failed in allocation \n", -1);
	if (!*map)
		ft_error_close(ft_free_map(map), "read nothing \n", -1);
	data->map = map;
	// ft_free_map(map);
	ft_check_all(data);
}

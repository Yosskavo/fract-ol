/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:22:03 by yel-mota          #+#    #+#             */
/*   Updated: 2025/04/09 17:17:40 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_all(t_data *data)
{
	int	len;

	len = ft_tablen((const char **)data->map);
	if (!ft_check_len(data->map))
		ft_error_close(ft_free_map(data->map), SHAPE_ERROR, -1);
	if (!ft_check_walls(data->map, len))
		ft_error_close(ft_free_map(data->map), WALLS_ERROR, -1);
	if (!ft_check_comp(data))
		ft_error_close(ft_free_map(data->map), COMPONENET_ERROR, -1);
	if (!ft_fllod_fill(data))
		ft_error_close(ft_free_map(data->map), MAP_ERROR, -1);
}

char	*ft_check_content(int fd)
{
	char	*tmp;
	char	*cont;
	int		i;

	cont = ft_strdup("");
	if (!cont)
		ft_error_close(NULL, MALLOC_ERROR, fd);
	tmp = ft_strdup(" ");
	if (!tmp)
		ft_error_close(cont, MALLOC_ERROR, fd);
	i = 1;
	while (i > 0)
	{
		i = read(fd, tmp, 1);
		if (i == 0)
			break ;
		if (i < 0)
			ft_free_all(cont, tmp, READ_ERROR, fd);
		cont = ft_strjoin(cont, tmp);
		if (!cont)
			ft_error_close(tmp, MALLOC_ERROR, fd);
	}
	free(tmp);
	return (cont);
}

int	ft_check_filename(char *filename)
{
	int	i;
	int	fd;

	i = ft_strlen(filename) - ft_strlen(EXTENSION);
	if (i <= 0 || filename[i - 1] == '/')
		ft_error_0(FILE_ERROR);
	if (!ft_strcmp(filename + i, EXTENSION))
		ft_error_0(EXTENSION_ERROR);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error_0(OPEN_ERROR);
	return (fd);
}

void	ft_check(char *filename, t_data *data)
{
	int		fd;
	char	**map;
	char	*cont;

	fd = ft_check_filename(filename);
	cont = ft_check_content(fd);
	if (ft_strnstr(cont, "\n\n", ft_strlen(cont)))
		ft_error_close(cont, NEWLINE_ERROR, fd);
	close(fd);
	map = ft_split(cont, '\n');
	free(cont);
	if (!map)
		ft_error_close(ft_free_map(map), MALLOC_ERROR, -1);
	if (!*map)
		ft_error_close(ft_free_map(map), READ_ERROR, -1);
	data->map = map;
	ft_check_all(data);
}

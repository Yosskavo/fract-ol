/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:22:56 by yel-mota          #+#    #+#             */
/*   Updated: 2025/04/08 16:33:25 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "/usr/include/minilibx-linux/mlx.h"
# include "/usr/include/minilibx-linux/mlx_int.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef PACK
#  define EXTENSION ".ber"
#  define PLAYER 'P'
#  define WALLS '1'
#  define COLLECT 'C'
#  define FREESPACE '0'
#  define EXIT 'E'
# endif

typedef struct s_data
{
	char	**map;
	int		hight;
	int		lenght;
	int		x_player;
	int		y_player;
	int		c_count;
	int		x_exit;
	int		y_exit;
	int		i;
	int		j;
	// tools of mlx
	void	*y_init;
	void	*y_wind;
}			t_data;

void		ft_free_all(char *str, char *str2, char *mess, int fd);
int			ft_strcmp(char *str1, char *str2);
void		ft_error_0(char *str);
void		ft_error_close(char *str, char *mess, int fd);
void		ft_check(char *filename, t_data *data);
char		*ft_free_map(char **str);
int			ft_tablen(const char **s);
int			ft_check_walls(char **map, int len);
int			ft_check_comp(t_data *data);
int			ft_check_len(char **str);
int			ft_fllod_fill(t_data *data);

#endif

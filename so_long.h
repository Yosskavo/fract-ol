/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:22:56 by yel-mota          #+#    #+#             */
/*   Updated: 2025/04/09 23:01:01 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "/usr/include/minilibx-linux/mlx.h"
# include "/usr/include/minilibx-linux/mlx_int.h"
# include "ft_printf.h"
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
#  define GAME_NAME "I AM LIER"
# endif

# ifndef PACK_ERROR
#  define INPUT_ERROR "ERROR\n input -> ./so_long <map.ber>\n"
#  define MALLOC_ERROR "ERROR\n failed in allocation \n"
#  define READ_ERROR "ERROR\n read nothing \n"
#  define NEWLINE_ERROR "ERROR\n there is a new line in your map\n"
#  define FILE_ERROR "ERROR\n invalid map name or wrong extension\n"
#  define EXTENSION_ERROR "ERROR\n wrong or no extension\n"
#  define OPEN_ERROR "ERROR\n no such a file or permission denied\n"
#  define SHAPE_ERROR "ERROR\n the shape of map incoerrect \n"
#  define WALLS_ERROR "ERROR\n messing walls \n"
#  define COMPONENET_ERROR "ERROR\n miss or more (P, E, C)\n"
#  define MAP_ERROR "ERROR\n invalide map \n"
#  define INIT_ERROR "ERROR\n faild to make connection\n"
#  define WINDOW_ERROR "ERROR\n faild to creat a window\n"
#  define IMAGE_ERROR "ERROR\n no such a file or diractory\n"
# endif

# ifndef SIZE_MAP
#  define WIDTH 64
#  define HIGHT 64
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
	void	*y_init;
	void	*y_wind;
	void	*y_p;
	void	*y_w;
	void	*y_c;
	void	*y_s;
	void	*y_e;
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
void		ft_up(t_data *data, char **map, int *i);
void		ft_down(t_data *data, char **map, int *i);
void		ft_right(t_data *data, char **map, int *i);
void		ft_left(t_data *data, char **map, int *i);
void		ft_escape(t_data *data);
void		ft_start(t_data *data);
void		ft_putimage(t_data *data);
void		ft_free_1(void *y_init, void *y_wind, int status_exit);
int			close_wind(void *ptr);
int			key_handler(int key, void *ptr);
void		ft_putxpm(t_data *data);

#endif
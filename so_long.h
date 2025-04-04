#ifndef SO_LONG_H
# define SO_LONG_H

# include "/usr/include/minilibx-linux/mlx.h"
# include "/usr/include/minilibx-linux/mlx_int.h"
# include <X11/keysym.h>
# include <unistd.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "ft_printf.h"

# ifndef EXTENSION
#  define EXTENSION ".ber"
# endif


int	ft_strcmp(char *str1, char *str2);
void	ft_error_0(char *str);
void	ft_error_close(char *str, char *mess, int fd);
void	ft_check(char *filename);

# endif

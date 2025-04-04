#include "so_long.h"

void ft_error_close(char *str, char *mess, int fd)
{
	if (str != NULL)
		free(str);
	ft_putstr_fd(mess, fd);
	close(fd);
	exit(1);
}

void ft_error_0(char *str)
{
	ft_printf("%s\n", str);
	exit(1);
}


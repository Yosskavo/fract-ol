#include "so_long.h"

void ft_check_content(int fd)
{
	char **map;
	int i;

	i = 0;
	str[i]
}

int	ft_check_filename(char *filename)
{
	int i;

	i = ft_strlen(filename) - ft_strlen(EXTENSION);
	if (i <= 0 || filename[i - 1] == '/')
		ft_error_0("invalid map name or wrong extension");
	if (!ft_strcmp(filename + i, EXTENSION))
		ft_error_0("wrong or no extension");
	int fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error_0("no such a file or permission denied");
	return (fd);
}

void ft_check(char *filename)
{
	int fd;

	fd = ft_check_filename(filename);
	ft_check_content(fd);
}

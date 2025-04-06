#include "so_long.h"

int ft_tablen(const char **s)
{
	int	i;

	i = 0;
	while (s[i] != NULL)
		i++;
	return (i);
}


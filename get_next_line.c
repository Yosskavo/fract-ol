/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 04:16:51 by yel-mota          #+#    #+#             */
/*   Updated: 2025/04/05 18:17:49 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (free(s1), NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*ft_strread(int fd, char *dest)
{
	char	*str;
	char	*tmp;
	ssize_t	i;

	str = malloc(sizeof(char) * ((unsigned long long)BUFFER_SIZE + 1));
	if (str == NULL)
		return (NULL);
	if (!dest)
		dest = ft_strdup("");
	i = 1;
	while (i != 0)
	{
		i = read(fd, str, BUFFER_SIZE);
		if (i == -1)
			return (free(str), free(dest), NULL);
		str[i] = '\0';
		tmp = ft_strdup(dest);
		free(dest);
		dest = ft_strjoin(tmp, str);
		free(tmp);
		if (ft_whereline(str) != 0 || i == 0)
			break ;
	}
	return (free(str), dest);
}

char	*ft_strline(char *str)
{
	ssize_t	i;
	ssize_t	j;
	char	*dest;

	if (!str)
		return (NULL);
	i = ft_whereline(str);
	if ((i - 1) == -1)
	{
		i = ft_strlen(str);
		dest = malloc(sizeof(char) * (i + 1));
	}
	else
		dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	j = 0;
	while (j < i)
	{
		dest[j] = str[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	*ft_strrest(char *str)
{
	char	*dest;
	int		j;
	int		i;

	if (!str)
		return (NULL);
	i = ft_whereline(str);
	if ((i - 1) == -1)
		return (free(str), ft_strdup(""));
	else
		dest = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!dest)
		return (NULL);
	j = 0;
	while (str[i + j] != '\0')
	{
		dest[j] = str[i + j];
		j++;
	}
	dest[j] = '\0';
	return (free(str), dest);
}

char	*get_next_line(int fd)
{
	static char	*dest;
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	dest = ft_strread(fd, dest);
	if (!dest)
		return (NULL);
	if (*dest == '\0')
		return (free(dest), NULL);
	str = ft_strline(dest);
	if (!str)
		return (NULL);
	dest = ft_strrest(dest);
	if (!dest)
		return (NULL);
	return (str);
}

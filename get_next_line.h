/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 21:34:18 by yel-mota          #+#    #+#             */
/*   Updated: 2025/04/05 18:17:56 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strrest(char *str);
char	*ft_strline(char *str);
char	*ft_strread(int fd, char *dest);
char	*ft_strjoin(char *s1, char const *s2);
size_t	ft_whereline(const char *str);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 77
# endif

#endif

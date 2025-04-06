#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
size_t ft_strlen(const char *str);
char	**ft_split(const char *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char *ft_strdup(const char *s);
size_t ft_strlcpy(char *dest, const char *src, size_t size);
void ft_putstr_fd(char *str, int fd);
void	ft_putchar_fd(char c, int fd);
char	*ft_strnstr(const char *big, const char *little, size_t len);
void	*ft_memset(void *s, int c, size_t n);

#endif

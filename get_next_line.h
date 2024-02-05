#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 13
# endif

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

char	*get_next_line(int fd);
char *read_file(int fd, char *big_buf);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int	ft_strlen(char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);

# endif
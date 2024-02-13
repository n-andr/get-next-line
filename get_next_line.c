/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:49:22 by nandreev          #+#    #+#             */
/*   Updated: 2024/02/07 14:49:42 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
//c-p from utils

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	if (str == NULL)
		return (0);
	while (*str != '\0')
	{
		str ++;
		length ++;
	}
	return (length);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (src == NULL)
		return (0);
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

/* <size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	ret;

	i = 0;
	while (*dst && i < dstsize)
	{
		++dst;
		++i;
	}
	ret = ft_strlcpy(dst, src, dstsize - i);
	return (ret + i);
} */

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s_join;
	size_t	total_len;

	total_len = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	s_join = malloc (total_len * sizeof(char));
	if (total_len == 0 || s_join == 0)
		return (NULL);
	ft_strlcpy(s_join, s1, ft_strlen((char *)s1) + 1);
	ft_strlcpy(s_join + ft_strlen((char *)s1), s2, ft_strlen((char *)s2) + 1);
	return (s_join);
}

char	*ft_strchr(const char *s, int c)
{
	char	*s1;
	char	ch;

	ch = (char)c;
	s1 = (char *)s;
	while (*s1 != '\0')
	{
		if (*s1 == ch)
			return (s1);
		s1++;
	}
	if (*s1 == ch)
		return (s1);
	return (NULL);
}

// end c-p from utilis


/* char	*rewrite_buf(char *big_buf)
{
	char	*big_buf_dub;
	int	i;

	i = 0;
	while (big_buf[i] != '\n')
		i ++;
	big_buf_dub = malloc (sizeof(char) * (ft_strlen(big_buf) - i));
	if (big_buf_dub == NULL)
		return (NULL);
	ft_strlcpy(big_buf_dub, (big_buf + i + 1), (ft_strlen(big_buf) - i));
	free (big_buf);
	big_buf = malloc (sizeof(char) * (ft_strlen(big_buf_dub) + 1));
	if (big_buf == NULL)
		return (NULL);
	ft_strlcpy(big_buf, big_buf_dub, (ft_strlen(big_buf_dub) + 1));
	free (big_buf_dub);
	return (big_buf);
} */

char	*split_buf(char *big_buf)
{
	char	*read_line;
	int	i;

	i = 0;
	while (big_buf[i] != '\n')
		i ++;
	read_line = malloc (sizeof(char) * (i + 2));
	if (read_line == NULL)
		return (NULL);
	ft_strlcpy (read_line, big_buf, (i + 2));
	//big_buf = rewrite_buf(big_buf);
	ft_strlcpy(big_buf, (big_buf + i + 1), (ft_strlen(big_buf) - i));
	//find /n and split in two
	//разбить big_buf на линию, которую возвращаем и остаток big_buf  ---> in other function
	return (read_line);
}

char	*read_file(int fd, char *big_buf)
{
	char	read_buf[BUFFER_SIZE + 1];
	char	*big_buf_dub;
	int		bytes_read;

	read_buf[0] = '\0';
	while (ft_strchr(read_buf, '\n') == NULL)
	{
		bytes_read = read (fd, read_buf, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		read_buf[BUFFER_SIZE] = '\0';
		big_buf_dub = ft_strjoin(big_buf, read_buf);
		free (big_buf);
		big_buf = malloc (sizeof(char) * (ft_strlen(big_buf_dub) + 1));
		if (big_buf == NULL)
		{
			free (big_buf_dub);
			return (NULL);
		}
		ft_strlcpy(big_buf, big_buf_dub, (ft_strlen(big_buf_dub)+1));
		free (big_buf_dub);
	}
	return(big_buf);
}

char	*get_next_line(int fd)
{
	static char	*big_buf;
	char	*read_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	big_buf = read_file (fd, big_buf);
	if (big_buf == NULL || *big_buf == '\0') // need to check if this syntax is correct maybe !big_buf 
		return(NULL);
		//need to free(big_buf);???
	read_line = split_buf(big_buf);


	//
	//
	//To DO: work with the end of the file
	//
	//


	//printf("BIG_BUF:%s\n", big_buf); 
	return (read_line);
}

/* // #include <stdio.h>
#include <fcntl.h>

int	main()
{

	int	fd;

	// Making the standart output our file, so every time we run a program (./a.out) we write one more hello in the file
	// dup2 duplicates the file descriptor fd to file descriptor 1 (standard output). This redirects the standard output to the opened file.

	// fd = open ("file.txt", O_RDWR | O_CREAT | O_APPEND);
	// dup2 (fd, 1);
	// write (1, "hello", 5);

	// char	buf[256];
	// int	chars_read;

	fd = open ("file.txt", O_RDWR);
	printf ("%s", get_next_line(fd));
	printf ("%s", get_next_line(fd));
	printf ("%s", get_next_line(fd));
	printf ("%s", get_next_line(fd));
	printf ("%s", get_next_line(fd));
	printf ("%s", get_next_line(fd));
	//printf ("%s", get_next_line(fd));
	

// printf("line27");
// fflush(stdout);
	// Writing all the content from file.txt 40 simbols at a time.
	
	// while ((chars_read = read (fd, buf, 40)))
	// {
	// 	buf[chars_read] = '\0';
	// 	printf ("line 40 char: %s\n", buf);
	// }
	return (0);
} */
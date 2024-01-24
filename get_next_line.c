#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	read_buf[BUFFER_SIZE + 1];
	int	i;
	char	*read_line;
	int	len;
	ssize_t	bytes_read;


	bytes_read = read (fd, read_buf, BUFFER_SIZE);
	if (bytes_read <= 0)
        return NULL;
	read_buf[BUFFER_SIZE] = '\0';
	len = 0;
	//посчитаем длину до разрыва строки 
	while (read_buf[len] != '\n' && len < BUFFER_SIZE)
		len++;
	read_line = malloc(sizeof(char) * (len + 1));
	if (read_line == NULL)
		return (NULL);
	i = 0;
	while (read_buf[i] != '\n' && i < BUFFER_SIZE)
	{
		read_line[i] = read_buf[i];
		i++;
	}
	read_line[i] = '\0';
	return (read_line);
}


// #include <stdio.h>
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
	printf ("%s\n", get_next_line(fd));
	printf ("%s\n", get_next_line(fd));
	printf ("%s\n", get_next_line(fd));
	printf ("%s\n", get_next_line(fd));
	printf ("%s\n", get_next_line(fd));
	printf ("%s\n", get_next_line(fd));
	// Writing all the content from file.txt 40 simbols at a time.
	
	// while ((chars_read = read (fd, buf, 40)))
	// {
	// 	buf[chars_read] = '\0';
	// 	printf ("line 40 char: %s\n", buf);
	// }
	return (0);
}
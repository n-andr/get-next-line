#include "get_next_line.h"

char	*get_next_line(int fd)
{
	
}


#include <stdio.h>
#include <fcntl.h>

int	main()
{
	int	fd;

	// Making the standart output our file, so every time we run a program (./a.out) we write one more hello in the file
	// dup2 duplicates the file descriptor fd to file descriptor 1 (standard output). This redirects the standard output to the opened file.

	// fd = open ("file.txt", O_RDWR | O_CREAT | O_APPEND);
	// dup2 (fd, 1);
	// write (1, "hello", 5);

	char	buf[256];
	int		chars_read;

	fd = open ("file.txt", O_RDWR);

	while ((chars_read = read (fd, buf, 40)))
	{
		buf[chars_read] = '\0';
		printf ("line 40 char: %s\n", buf);
	}
	return (0);
}
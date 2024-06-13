# get-next-line
 
## Overview

This project is part of the 42 school curriculum, where the objective is to implement the function `get_next_line`, which reads a line from a file descriptor.

## Key Features

- **Single Line Reading**: Efficiently reads one line at a time from a file descriptor.
- **Buffer Management**: Handles buffer management to optimize reading operations.
- **Memory Management**: Ensures efficient memory allocation and deallocation.

## Getting Started

Clone the repository and follow the instructions in the `Makefile` to compile and run the project.

```bash
git clone https://github.com/n-andr/get-next-line.git
cd get-next-line
make
```

## Usage

To use the get_next_line function in your C program, include the get_next_line.h header file and call the get_next_line function with the appropriate file descriptor.

```c
#include "get_next_line.h"

int main() {
    int fd = open("file.txt", O_RDONLY);
    char *line;
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s\n", line);
        free(line);
    }
    close(fd);
    return 0;
}
```


## Future Projects

This project is particularly useful for future projects like [so_long](https://github.com/n-andr/so_long), where reading from files is necessary.

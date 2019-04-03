# 42_get_next_line
# Project status - In Progress
This project, get_next_line, opens and reads a file or input from a user and then prints out a line.

Below are some notes on the functions that are being used.
int	 open	(const char *filepath,	 int flag);

RETURN VALUE: open() returns an int value, which is the file descriptor. If a file is not read successfully, then the file descriptor of -1 is returned. If a file is read successfully then a small, but a non-negative number is returned.

Flag has the following access modes: O_RDONLY, O_WRONLY, O_RDWR.

O_RDONLY stands for read only.

O_WRONLY stands for write only.

O_RDWR stands for read/write.


To compile include libft library as shown below:

gcc get_next_line.c -I. ./libft/libft.a

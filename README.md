# 42_get_next_line
# Project status - In Progress
This project, get_next_line, opens and reads a file or input from a user and then prints out a line.

Below are some notes on the functions that are being used.
int	 open	(const char *filepath,	 int flag);

RETURN VALUE: open() returns an int value, which is the file descriptor. If a file is not read successfully, then the file descriptor of -1 is returned. If a file is read successfully then a small, but a non-negative number is returned.

Flag has the following access modes: O_RDONLY, O_WRONLY, O_RDWR.

O_RDONLY stands for read only. O_WRONLY stands for write only. O_RDWR stands for read/write.

To compile, include libft library as shown below:
```
gcc get_next_line.c -I. ./libft/libft.a
```
Wall Wextra Werror flag can be used to compile, which is helpful in raising warnings if a variable is left uninitalized:
```
gcc -Wall -Wextra -Werror get_next_line.c -I. ./libft/libft.a
```
# Return Value of get_next_line
get_next_line returns -1, 0, or 1.
+ Returns 1 if a line has been read successfuly.
+ Returns 0 if the program is finished reading the file. This will occur when the last line of a file is read.
+ Returns -1 if the program was unable to read the file.
